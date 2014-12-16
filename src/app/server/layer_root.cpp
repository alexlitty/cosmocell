#include <network/constant.hpp>
#include <network/object.hpp>
#include <server/layer_root.hpp>

// Root layer constructor.
cosmocell::layer::server::root::root() : m_socket(cosmocell::network::port::external)
{
    std::cout << std::endl << "[cosmocell] Server initialized." << std::endl;
}

// Perform root program.
bool cosmocell::layer::server::root::execute()
{
    cosmodon::buffer buffer;
    std::string address;
    cosmocell::network::object object;

    auth_request auth_req;

    cosmocell::account_record account;
    std::string username;
    std::string password;

    // Listen for messages.
    while (m_socket.receive(buffer, address)) {
        try {
            buffer >> object;

            // Authentication request.
            if (object == cosmocell::network::object::AUTH_REQUEST) {
                auth_req.network_deserialize(buffer);
                account = m_auth.authenticate(username, password);

                // Provide an authentication reply.
                buffer.clear();
                account.network_serialize(buffer);
                m_socket.send(buffer, address);

                // Output status message.
                std::cout << "[" << account.username << "] ";
                if (account.valid()) {
                    std::cout << "Authenticated." << std::endl;
                } else {
                    std::cout << "Failed authentication." << std::endl;
                }
            }
        }

        // Catch buffer overflows.
        catch (const cosmodon::exception::error &e) {
            continue;
        }
    }

    // Signal more execution.
    return true;
}
