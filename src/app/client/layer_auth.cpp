#include <client/layer_auth.hpp>
#include <network/object.hpp>
#include <network/constant.hpp>

// Constructor.
cosmocell::layer::client::auth::auth(cosmodon::socket::udp &socket, std::string &username, std::string &password, uint8_t attempts_max)
  : m_attempts(0), m_attempts_max(attempts_max), m_timed_out(false), m_account()
{
    m_socket = &socket;
    m_buffer.clear();

    // Prepare authentication request.
    cosmocell::auth_request request;
    request.username = username;
    request.password = password;

    // Send request.
    request.network_serialize(m_buffer);
    send();

    // Start elapsed time measurement.
    m_attempts++;
    m_clock.reset();
}

// Send authentication information.
void cosmocell::layer::client::auth::send()
{
    m_socket->send(m_buffer, cosmocell::network::address::server);
}

// Perform a tick.
bool cosmocell::layer::client::auth::execute()
{
    cosmodon::buffer buffer;
    cosmocell::network::object obj;
    cosmocell::auth_reply reply;
    std::string address;

    // Check for authentication reply.
    while (m_socket->receive(buffer, address)) {
        std::cout << "Message found, and it is ";
        if (buffer.length() != 0) {
            buffer >> obj;

            // Reply found. If valid, stop layer.
            if (obj == cosmocell::network::object::AUTH_REPLY) {
                std::cout << "correct.";
                if (reply.network_deserialize(buffer)) {
                    m_account = reply.account;
                    return false;
                }
            } else {
                std::cout << "incorrect.";
            }
        }
        std::cout << std::endl;
    }

    // Re-send authentication, or quit.
    if (m_clock.elapsed() > 3) {
        if (m_attempts++ < m_attempts_max) {
            send();
        } else {
            m_timed_out = true;
            return false;
        }
    }
    return true;
}

// Determine if authentication timed out.
bool cosmocell::layer::client::auth::timed_out() const
{
    return m_timed_out;
}

// Determine authentication result.
bool cosmocell::layer::client::auth::result() const
{
    return m_account.valid();
}

// Retrieve account.
cosmocell::account_record cosmocell::layer::client::auth::get_account() const
{
    return m_account;
}
