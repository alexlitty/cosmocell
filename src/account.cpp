#include <account.hpp>

using namespace cosmocell;

// Constructor.
account::account(uint64_t id, std::string username)
{
    m_id = id;
    m_username = username;
}

// Retrieves ID.
uint64_t account:get_id() const
{
    return m_id;
}

// Retrieves username.
std::string account::get_username() const
{
    return m_username;
}
