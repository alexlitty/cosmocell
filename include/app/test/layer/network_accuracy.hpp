#ifndef COSMOCELL_APP_TEST_LAYER_NETWORK_ACCURACY
#define COSMOCELL_APP_TEST_LAYER_NETWORK_ACCURACY

#include "base.hpp"

namespace cosmocell
{
    namespace layer
    {
        namespace test
        {
            /**
             * Ensures bits are being sent and received accurately.
             */
            class network_accuracy : public base
            {
            protected:
                // Socket to perform test with.
                cosmodon::socket::udp m_socket;

                // Buffer to use with socket.
                cosmodon::buffer m_buffer;

                // Timer to measure elapsed time.
                cosmodon::clock m_timer;

            public:
                /**
                 * Constructor.
                 */
                network_accuracy();

                /**
                 * Prepares accuracy test.
                 */
                void prepare();

                /**
                 * Perform a tick on the layer.
                 */
                bool execute();
            };
        }
    }
}

#endif
