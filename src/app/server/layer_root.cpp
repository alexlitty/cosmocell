#include <network/constant.hpp>
#include <server/layer_root.hpp>

// Root layer constructor.
cosmocell::layer::server::root::root() : m_socket(cosmocell::network::port::external)
{

}

// Perform root program.
bool cosmocell::layer::server::root::execute()
{
    return true;
}
