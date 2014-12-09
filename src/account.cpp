#include <account.hpp>

using namespace cosmocell;

// Constructor.
account::account(uint64_t id, std::string username)
{
    m_id = id;
    m_username = username;
}

// Retrieves username.
std::string account::get_username()
{
    return m_username;
}
