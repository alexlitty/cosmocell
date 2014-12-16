#include <account.hpp>
#include <network/object.hpp>

using namespace cosmocell;

// Constructor.
account_record::account_record(uint64_t new_id, std::string new_username) : id(new_id), username(new_username)
{

}

// Determines validity of account.
bool account_record::valid() const
{
    return (id != 0);
}

// Serialize Account.
void cosmocell::account_record::network_serialize(cosmodon::buffer &buffer)
{
    buffer << id;
    if (id != 0) {
        buffer << username;
    }
}

// Deserialize Account.
bool cosmocell::account_record::network_deserialize(cosmodon::buffer &buffer)
{
    account_record(0, "");

    // Deserialize.
    try {
        buffer >> id;
        if (id != 0) {
            buffer >> username;
        }
    }

    // Catch errors.
    catch (const cosmodon::exception::error &e) {
        return false;
    }
    return true;
}

// Serialize Authentication Request.
void cosmocell::auth_request::network_serialize(cosmodon::buffer &buffer)
{
    buffer << cosmocell::network::object::AUTH_REQUEST;
    buffer << username;
    buffer << password;
}

// Deserialize Authentication Request.
bool cosmocell::auth_request::network_deserialize(cosmodon::buffer &buffer)
{
    // Deserialize.
    try {
        buffer >> username;
        buffer >> password;
    }

    // Catch errors.
    catch (cosmodon::exception::error &e) {
        return false;
    }
    return true;
}

// Serialize Authentication Reply.
void cosmocell::auth_reply::network_serialize(cosmodon::buffer &buffer)
{
    buffer << cosmocell::network::object::AUTH_REPLY;
    account.network_serialize(buffer);
}

// Deserialize Authentication Reply.
bool cosmocell::auth_reply::network_deserialize(cosmodon::buffer &buffer)
{
    return account.network_deserialize(buffer);
}
