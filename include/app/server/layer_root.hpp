#ifndef COSMOCELL_APPS_CLIENT_LAYER_ROOT
#define COSMOCELL_APPS_CLIENT_LAYER_ROOT

#include <cosmodon/cosmodon.hpp>

namespace cosmocell
{
    namespace layer
    {
        namespace client
        {
            class root : public cosmodon::layer::base
            {
                // Network context.
                network::context *m_context;

                // 

            public:
                // Perform a tick on the root layer.
                bool tick();
            };
        }
    }
}

#endif
