#ifndef COSMOCELL_APPS_SERVER_LAYER_ROUTE
#define COSMOCELL_APPS_SERVER_LAYER_ROUTE

#include <cosmodon/cosmodon.hpp>

namespace cosmocell
{
    namespace layer
    {
        namespace server
        {
            /**
             * A layer which routes messages between clients and servers.
             */
            class route : public cosmodon::layer::base
            {
            protected:
                // Socket to push REQ-REP server messages.
                network::socket m_server_out;

                // Replying Socket to pull server messages.
                network::socket m_server_in;

                // Socket to push client messages.
                network::socket m_client_out;



            public:
                // Perform routing.
                bool tick();
            };
        }
    }
}

#endif
