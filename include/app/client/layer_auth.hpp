#ifndef COSMOCELL_CLIENT_LAYER_AUTH
#define COSMOCELL_CLIENT_LAYER_AUTH

#include <cosmodon/cosmodon.hpp>
#include <account.hpp>

namespace cosmocell
{
    namespace layer
    {
        namespace client
        {
            /**
             * A non-graphical layer that performs server authentication.
             *
             * While the layer exists, it is determining the success of the authentication.
             */
            class auth : public cosmodon::layer
            {
                // Socket to perform authentication with.
                cosmodon::socket::udp *m_socket;

                // Buffer, containing authentication request.
                cosmodon::buffer m_buffer;

                // Clock to determine previous request time.
                cosmodon::clock m_clock;

                // Authentication attempt counter.
                uint8_t m_attempts;

                // Authentication attempt maximum.
                uint8_t m_attempts_max;

                // Indicates authentication timed out.
                bool m_timed_out;

                // Account information.
                account_record m_account;

                /**
                 * Sends the buffer, filled with authentication information.
                 */
                void send();

            public:
                /**
                 * Constructor.
                 *
                 * Provided socket must be initialized, and may not be used externally until
                 * authentication completes.
                 *
                 * Acts as a reset method, to use the same instance for multiple authentications.
                 */
                auth(cosmodon::socket::udp &socket, std::string &username, std::string &password, uint8_t attempts_max = 1);

                /**
                 * Perform a tick.
                 */
                virtual bool execute();

                /**
                 * Determine if authentication timed out.
                 *
                 * Returns true if the authentication server did not respond quickly enough, false
                 * otherwise.
                 */
                bool timed_out() const;

                /**
                 * Determine the result of authentication.
                 *
                 * Returns true if authentication was successful, false otherwise. Returns false if
                 * authentication is in progress.
                 */
                bool result() const;

                /**
                 * Return an account filled with authentication results.
                 *
                 * If authentication is in progress, the account will be invalid.
                 */
                account_record get_account() const;
            };
        }
    }
}

#endif
