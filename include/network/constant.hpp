#ifndef COSMOCELL_NETWORK_CONSTANT
#define COSMOCELL_NETWORK_CONSTANT

#include <cstdint>
#include <string>

namespace cosmocell
{
    namespace network
    {
        /**
         * Commonly used addresses.
         */
        namespace address
        {
            extern std::string server;
        }

        /**
         * Commonly used ports.
         */
        namespace port
        {
            extern uint16_t external;
        }
    }
}

#endif
