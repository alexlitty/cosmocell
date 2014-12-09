#include <network/message.hpp>

using namespace cosmocell::network;

// Constructor.
message::message()
{
    m_category = message::category_t::INVALID;
}

// Constructor using a network buffer.
message::message(cosmodon::network::buffer &buff)
{
    interpret(buff);
}

// Clears message.
void message::clear()
{
    m_category = message::category_t::INVALID;
}

// Interpret a network buffer into a message.
bool message::interpret(cosmodon::network::buffer &buff)
{
    category_t category;

    // Interpret category.
    buff.read(category);
    if (category >= message::category_t::COUNT || category == message::category_t::INVALID) {
        clear();
        return false;
    }

    // Copy data.
    m_data.write(buff.read_raw(buff.size() - 1), buff.size() - 1);
    return true;
}

// Set category.
void message::set_category(message::category_t category)
{
    m_category = category;
}

// Retrieve category.
message::category_t message::get_category()
{
    return m_category;
}

// Set data.
void message::set_data(cosmodon::network::buffer &data)
{
    m_data.clear();
    m_data.write(data.read_raw(data.size()), data.size());
}

// Retrieve data.
cosmodon::network::buffer message::get_data()
{
    return m_data;
}

// Convert to network buffer.
message::operator network::buffer()
{
    network::buffer buff;
    buff.write(m_category);
    buff.write(m_data.read_raw(m_data.size()), m_data.size());
    return buff;
}
