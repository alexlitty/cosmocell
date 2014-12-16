#include <network/object.hpp>

cosmodon::buffer& operator <<(cosmodon::buffer &buffer, cosmocell::network::object object)
{
    uint8_t temp = static_cast<uint8_t>(object);
    buffer << temp;
    return buffer;
}
