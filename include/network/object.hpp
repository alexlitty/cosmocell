#ifndef COSMOCELL_NETWORK_OBJECT
#define COSMOCELL_NETWORK_OBJECT

#include <cosmodon/cosmodon.hpp>

namespace cosmocell
{
    namespace network
    {
        /**
         * Enumeration for identifying types of network objects.
         */
        enum class object : uint8_t
        {
            AUTH_REQUEST,
            AUTH_REPLY,
        };
    }
}

/**
 * Buffer input stream operator.
 */
cosmodon::buffer& operator<<(cosmodon::buffer &buffer, cosmocell::network::object object);

#endif
