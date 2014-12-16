#ifndef COSMOCELL_APP_SERVER_LAYER_AUTH
#define COSMOCELL_APP_SERVER_LAYER_AUTH

#include <account.hpp>

namespace cosmocell
{
    namespace layer
    {
        namespace server
        {
            class auth
            {
            public:
                /**
                 * Maintain authenticated users.
                 */
                bool execute();

                /**
                 * Authenticates an account.
                 *
                 * Does not start a session for the account.
                 *
                 * Returns true if authentication was successful, false otherwise.
                 */
                account_record authenticate(std::string &username, std::string &password);
            };
        }
    }
}

#endif
