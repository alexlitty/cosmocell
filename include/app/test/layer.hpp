#ifndef COSMOCELL_TEST_LAYER
#define COSMOCELL_TEST_LAYER

#include <vector>
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
