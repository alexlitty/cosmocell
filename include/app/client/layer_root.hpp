#ifndef COSMOCELL_CLIENT_LAYER_ROOT
#define COSMOCELL_CLIENT_LAYER_ROOT

#include <cosmodon/cosmodon.hpp>

namespace cosmocell
{
    namespace layer
    {
        namespace client
        {
            /**
             * Top execution layer of the client.
             */
            class root : public cosmodon::layer
            {
                // Network socket.
                cosmodon::socket::udp m_socket;

                // Root game layer.
                cosmodon::layer *m_game;

            public:
                /**
                 * Constructor.
                 */
                root();

                /**
                 * Destructor.
                 */
                ~root();

                /**
                 * Perform tick.
                 */
                virtual bool execute();
            };
        }
    }
}

#endif
