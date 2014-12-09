#ifndef COSMOCELL_NETWORK_MESSAGE
#define COSMOCELL_NETWORK_MESSAGE

#include <cosmodon/cosmodon.hpp>

namespace cosmocell
{
    namespace network
    {
        /**
         * Message, which associates data with a header.
         *
         * Used to send information over a network.
         */
        class message
        {
            /**
             * Message category
             */
            enum class category_t : uint8_t
            {
                INVALID,
                PING,
                AUTH_REQUEST,
                AUTH_REPLY,
                CHAT_SEND,
                CHAT_UPDATE,
                COUNT,
            };

        protected:
            // Categorization of data associated with this message.
            category_t m_category;

            // Data associated with this message.
            network::buffer m_data;

        public:
            /**
             * Constructor.
             */
            message();

            /**
             * Constructor using a network buffer.
             */
            message(network::buffer &buff);

            /**
             * Clears message.
             *
             * Message will hold no data, labeled with the invalid category.
             */
            void clear();

            /**
             * Interprets a network buffer into a message.
             *
             * Returns true if buffer is successfully interpreted, false otherwise.
             */
            bool interpret(network::buffer &buff);

            /**
             * Sets the category of stored data.
             */
            void set_category(category_t category);

            /**
             * Retrieves the category of stored data.
             */
            category_t get_category();

            /**
             * Sets the data stored by this message.
             */
            void set_data(network::buffer &data);

            /**
             * Gets the data stored by this message.
             */
            network::buffer get_data();

            /**
             * Convert to network buffer.
             */
            operator network::buffer()
            {
                network::buffer buff;
                buff.write(m_category);
                buff.write(m_data.read_raw(m_data.size()), m_data.size());
                return buff;
            }
        };
    }
}

#endif
