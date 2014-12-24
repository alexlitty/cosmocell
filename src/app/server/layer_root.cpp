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
        if (buffer.length() == 0) {
            continue;
        }
        buffer >> object;

        // Authentication request.
        if (object == cosmocell::network::object::AUTH_REQUEST) {
            if (auth_req.network_deserialize(buffer)) {
                continue;
            }
            account = m_auth.authenticate(auth_req.username, auth_req.password);

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

    // Signal more execution.
    return true;
}
