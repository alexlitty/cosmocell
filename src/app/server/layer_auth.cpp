#include <server/layer_auth.hpp>

// Maintain authenticated users.
bool cosmocell::layer::server::auth::execute()
{
    return true;
}

// Authenticate an account.
cosmocell::account_record cosmocell::layer::server::auth::authenticate(std::string &username, std::string &password)
{
    return cosmocell::account_record(1, username);
}
