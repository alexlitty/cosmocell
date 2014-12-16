#ifndef COSMOCELL_APPS_SERVER_LAYER_ROOT
#define COSMOCELL_APPS_SERVER_LAYER_ROOT

#include <cosmodon/cosmodon.hpp>

namespace cosmocell
{
    namespace layer
    {
        namespace server
        {
            class root : public cosmodon::layer
            {
                // Socket.
                cosmodon::socket::udp m_socket;

                // Authentication layer.
                //cosmocell::layer::server::auth m_auth;

                // Chat layer.
                //cosmodon::layer::server::chat m_chat;

            public:
                /**
                 * Constructor.
                 */
                root();

                /**
                 * Perform server program.
                 */
                bool execute();
            };
        }
    }
}

#endif
