#ifndef COSMOCELL_APP_TEST_LAYER_ROOT
#define COSMOCELL_APP_TEST_LAYER_ROOT

#include <vector>
#include "base.hpp"

namespace cosmocell
{
    namespace layer
    {
        namespace test
        {
            /**
             * Root layer for the testing program.
             *
             * Runs all testbenches.
             */
            class root : public cosmodon::layer
            {
            protected:
                // Collection of testing layers.
                std::vector<base*> m_layers;

                // Indicates the current testing layer.
                uint8_t m_layer_current;

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
                 * Perform testing program.
                 */
                bool execute();
            };
        }
    }
}

#endif
