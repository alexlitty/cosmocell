#include <auth/authenticator.hpp>

using namespace cosmocell;

// Constructor.
authenticator::authenticator()
{

}

// Logs an account in.
uint64_t authenticator::log_in(std::string username, std::string password)
{
    account logged_account(m_accounts.size() + 1, username);
    m_accounts.push_back(logged_account);
    return logged_account.get_id();
}

// Logs an account out, if it is authenticated.
void authenticator::log_out(uint64_t id)
{
    uint64_t result = 0;

    // Find account.
    for (uint64_t i = 0; i < m_accounts.size(); i++) {
        if (m_accounts[i]->get_id() == id) {
            result = i;
            break;
        }
    }

    // Remove account from list.
    if (result != 0) {
        m_accounts.erase(result);
    }
}

// Checks if an account is logged in.
bool authenticator::is_logged_in(uint64_t id)
{
    for (uint64_t i = 0; i< m_accounts.size(); i++) {
        if (m_accounts[i]->get_id() == id) {
            return true;
        }
    }
    return false;
}
