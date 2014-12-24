#include <test/layer/graphic.hpp>

// Constructor.
cosmocell::layer::test::graphic::graphic() : m_window()
{

}

// Preapre graphic test.
void cosmocell::layer::test::graphic::prepare()
{

}

// Perform graphic test.
bool cosmocell::layer::test::graphic::execute()
{
    static cosmodon::color background(175, 100, 0);
    m_window.clear(background);
    return true;
}
