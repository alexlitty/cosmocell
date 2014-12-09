#ifndef COSMOCELL_ACCOUNT
#define COSMOCELL_ACCOUNT

namespace cosmocell
{
    class account
    {
    protected:
        // Unique Account ID.
        uint64_t m_id;

        // Username.
        std::string m_username;

    public:
        /**
         * Constructor.
         */
        account(uint64_t id, std::string username);

        /**
         * Retrieves account ID.
         */
        uint64_t get_id() const;

        /**
         * Retrieves username.
         */
        std::string get_username() const;
    };
}

#endif
