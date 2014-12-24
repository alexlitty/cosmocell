#ifndef COSMOCELL_APP_TEST_LAYER_BUFFER
#define COSMOCELL_APP_TEST_LAYER_BUFFER

#include "base.hpp"

namespace cosmocell
{
    namespace layer
    {
        namespace test
        {
            /**
             * Encompassing buffer test.
             *
             * Ensures buffer features act as desired.
             */
            class buffer : public base
            {
            protected:
                // Buffer to test.
                cosmodon::buffer m_buffer;

            public:
                /**
                 * Prepares buffer testing.
                 */
                void prepare();

                /**
                 * Perform buffer testing.
                 */
                bool execute();
            };
        }
    }
}

#endif
