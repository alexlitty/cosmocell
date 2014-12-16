#include <account.hpp>
#include <network/constant.hpp>
#include <client/layer_root.hpp>
#include <client/layer_auth.hpp>

// Constructor.
cosmocell::layer::client::root::root() : m_socket(cosmocell::network::port::external)
{
}

// Destructor.
cosmocell::layer::client::root::~root()
{
}

// Tick.
bool cosmocell::layer::client::root::execute()
{
    cosmocell::layer::client::auth *auth;
    std::string username, password;
    cosmocell::account_record account;

    // Authenticate.
    while (!m_game) {
        std::cout << std::endl;
        std::cout << "[cosmocell] Enter username: " << std::flush;
        std::cin >> username;
        std::cout << "[cosmocell] Enter password: " << std::flush;
        std::cin >> password;
        std::cout << "[cosmocell] Authenticating... " << std::flush;
        
        // Send credentials over new authentication layer, and wait for results.
        auth = new cosmocell::layer::client::auth(m_socket, username, password);
        while (auth->execute()) {
            usleep(100);
        }

        // Check for time-out.
        if (auth->timed_out()) {
            std::cout << "\r[cosmocell] Authentication timed out." << std::endl;
        }

        // Check results.
        else if (auth->result()) {
            std::cout << "\r[cosmocell] Authenticated successfully." << std::endl;
            account = auth->get_account();
            //m_game = 1;
        }

        // Delete authentication layer.
        delete auth;
    }
    return true;
}
