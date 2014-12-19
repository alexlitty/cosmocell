#include <vector>
#include <test/layer.hpp>

// Initialize the layer.
cosmocell::layer::test::root::root()
{
    // Prepare testbench layers.
    m_layer_current = 0;
    m_layers.push_back(new cosmocell::layer::test::buffer);
    m_layers.push_back(new cosmocell::layer::test::network_accuracy);
    m_layers.push_back(new cosmocell::layer::test::network_speed);

    // Prepare first program.
    m_layers[0]->prepare();
}

// Destruct the layer.
cosmocell::layer::test::root::~root()
{
    for (uint8_t i = 0; i < m_layers.size(); i++) {
        delete m_layers[i];
    }
}

// Perform tests.
bool cosmocell::layer::test::root::execute()
{
    // Check if more testbenches are available.
    if (m_layer_current >= m_layers.size()) {
        return false;
    }

    // Tick current testbench, and move onward if needed.
    if (!m_layers[m_layer_current]->execute()) {
        m_layer_current++;

        // Print next testbench's introductory message.
        if (m_layer_current < m_layers.size()) {
            m_layers[m_layer_current]->prepare();
        }
    }
    return true;
}
