#include <vector>
#include <test/layer.hpp>

using namespace cosmocell;

// Initialize the layer.
test::layer::root::root()
{
    // Prepare testbench layers.
    m_layer_current = 0;
    m_layers.push_back(new test::layer::network_speed());
    m_layers.push_back(new test::layer::network_accuracy());

    // Prepare testing program.
    m_layers[0]->intro();
}

// Destruct the layer.
test::layer::root::~root()
{

}

// Tick the layer.
bool test::layer::root::tick()
{
    // Check if more testbenches are available.
    if (m_layer_current >= m_layers.size()) {
        return false;
    }

    // Tick current testbench, and move onward if needed.
    if (!m_layers[m_layer_current]->tick()) {
        m_layer_current++;

        // Print next testbench's introductory message.
        if (m_layer_current < m_layers.size()) {
            m_layers[m_layer_current]->intro();
        }
    }
    return true;
}

// Print introductory message.
void test::layer::root::intro() const
{
    std::cout << std::endl;
}
