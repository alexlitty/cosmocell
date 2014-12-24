#ifndef COSMOCELL_APP_TEST_LAYER_BASE
#define COSMOCELL_APP_TEST_LAYER_BASE

#include <cosmodon/cosmodon.hpp>

namespace cosmocell
{
    namespace layer
    {
        namespace test
        {
            /**
             * Base layer for test layers.
             */
            class base : public cosmodon::layer
            {
            public:
                /**
                 * Performs last-minute preparations to start the test.
                 *
                 * At minimum, should print an introduction of the test to the screen.
                 */
                virtual void prepare() = 0;
            };
        }
    }
}

#endif
