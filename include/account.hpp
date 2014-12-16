#ifndef COSMOCELL_ACCOUNT
#define COSMOCELL_ACCOUNT

#include <cosmodon/cosmodon.hpp>

namespace cosmocell
{
    /**
     * Type definition for Account Identifiers.
     */
    typedef uint32_t account_id;

    /**
     * Account record.
     *
     * If Account ID is 0, this record contains no useful information.
     */
    struct account_record : cosmodon::component::network
    {
        // Unique Account ID.
        account_id id;

        // Username.
        std::string username;

        /**
         * Constructor.
         */
        account_record(uint64_t new_id = 0, std::string new_username = "");

        /**
         * Determines if this is a valid account.
         *
         * An invalid account may be instanced by failed authentication.
         */
        bool valid() const;

        /**
         * Serialize.
         *
         * If this account is invalid, only the Account ID is provided.
         */
        void network_serialize(cosmodon::buffer &buffer);

        /**
         * Deserialize.
         */
        bool network_deserialize(cosmodon::buffer &buffer);
    };

    /**
     * Stores information about an authentication request.
     */
    struct auth_request : cosmodon::component::network
    {
        // Username.
        std::string username;

        // Password.
        std::string password;

        /**
         * Serialize.
         */
        void network_serialize(cosmodon::buffer &buffer);

        /**
         * Deserialize.
         */
        bool network_deserialize(cosmodon::buffer &buffer);
    };

    /**
     * Authentication reply.
     *
     * Communicates the status of an authentication.
     */
    struct auth_reply : cosmodon::component::network
    {
        // Authenticated account.
        account_record account;

        /**
         * Serialize.
         */
        void network_serialize(cosmodon::buffer &buffer);

        /**
         * Deserialize.
         */
        bool network_deserialize(cosmodon::buffer &buffer);
    };
}

#endif
