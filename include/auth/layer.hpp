#ifndef COSMOCELL_AUTH_AUTHENTICATOR
#define COSMOCELL_AUTH_AUTHENTICATOR

#include <vector>
#include <account.hpp>

namespace cosmocell
{
    /**
     * Maintains a list of authenticated users and implements authentication.
     */
    class authenticator
    {
    protected:
        // List of authenticated users.
        std::vector<account> m_accounts;

    public:
        /**
         * Constructor.
         */
        auth();

        /**
         * Attempts to verify and log an account in.
         *
         * Returns a positive-integer Account ID upon success, 0 otherwise.
         */
        uint64_t log_in(std::string username, std::string password);

        /**
         * Logs an account out.
         *
         * The given user will no longer be authenticated.
         */
        void log_out(uint64_t username);

        /**
         * Checks if an account is currently logged in.
         *
         * Returns true if account is logged in, false otherwise.
         */
        bool is_logged_in(uint64_t id);
    };
}

#endif
