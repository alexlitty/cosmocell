#ifndef COSMOCELL_TEST_LAYER
#define COSMOCELL_TEST_LAYER

#include <cosmodon/cosmodon.hpp>

using namespace cosmodon;

namespace cosmocell
{
    namespace test
    {
        namespace layer
        {
            /**
             * Base layer for this testing suite.
             */
            class base : public cosmodon::layer::base
            {
            public:
                /**
                 * Prints an introductory message for testing layer.
                 */
                virtual void intro() const = 0;
            };

            /**
             * Root layer for the testing program.
             *
             * Runs all testbenches.
             */
            class root : public base
            {
            protected:
                // Network context.
                network::context *m_context;

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
                 * Perform a tick on the layer.
                 */
                bool tick();

                /**
                 * Prints introdutory message.
                 */
                virtual void intro() const;
            };

            /**
             * Measures speed of network with varying message sizes.
             */
            class network_speed : public base
            {
            protected:
                network::socket *m_in;
                network::socket *m_out;
                time_t m_timer;

            public:
                /**
                 * Constructor.
                 */
                network_speed(network::context *context);

                /**
                 * Destructor.
                 */
                ~network_speed();

                /**
                 * Perform a tick on the layer.
                 */
                bool tick();

                /**
                 * Initiates the test by starting the internal timer.
                 */
                void start();

                /**
                 * Prints introductory message.
                 */
                virtual void intro() const;
            };

            /**
             * Ensures bits are being sent and received accurately.
             */
            class network_accuracy : public base
            {
            protected:
                network::socket *m_alpha;
                network::socket *m_beta;
                time_t m_timer;

                /**
                 * Send data over one socket, and verify its reception onto another local socket.
                 *
                 * Returns false if the data was sent unsuccessfully.
                 */
                bool send_and_verify(network::buffer &data, network::socket *in, network::socket *out);
            
            public:
                /**
                 * Constructor.
                 */
                network_accuracy(network::context *context);

                /**
                 * Destructor.
                 */
                ~network_accuracy();

                /**
                 * Perform a tick on the layer.
                 */
                bool tick();

                /**
                 * Prints introductory message.
                 */
                virtual void intro() const;
            };
        }
    }
}

#endif
