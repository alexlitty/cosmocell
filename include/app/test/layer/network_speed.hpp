#ifndef COSMOCELL_APP_TEST_LAYER_NETWORK_SPEED
#define COSMOCELL_APP_TEST_LAYER_NETWORK_SPEED

#include "base.hpp"

namespace cosmocell
{
    namespace layer
    {
        namespace test
        {
            /**
             * Measures speed of network with varying message sizes.
             */
            class network_speed : public base
            {
            protected:
                // Socket to perform test with.
                cosmodon::socket::udp m_socket;

                // Buffer to send data.
                cosmodon::buffer m_buffer;

                // Buffer to receive data.
                cosmodon::buffer m_buffer_dummy;

                // Timer to measure elapsed time.
                cosmodon::clock m_timer;

            public:
                /**
                 * Constructor.
                 */
                network_speed();

                /**
                 * Prepares speed test.
                 */
                void prepare();

                /**
                 * Perform speed test.
                 */
                bool execute();
            };
        }
    }
}

#endif
