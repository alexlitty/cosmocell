#include <server/layer_root.hpp>

int main()
{
    // Run server.
    try {
        cosmodon::layer *program = new cosmocell::layer::server::root;
        cosmodon::engine engine(program);
        engine.execute();
    }

    // Catch errors.
    catch (const cosmodon::exception::base &e) {
        std::cout << std::endl << "[error] " << e.what() << std::endl;
    }
    return 0;
}
