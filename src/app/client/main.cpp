#include <client/layer_root.hpp>

using namespace cosmocell;

int main()
{
    // Run client.
    try {
        cosmodon::layer *program = new layer::client::root;
        cosmodon::engine cosmodon_engine(program);
        cosmodon_engine.execute();
    }

    // Catch errors.
    catch (const cosmodon::exception::base &e) {
        std::cout << std::endl << "[error] " << e.what() << std::endl;
    }
    return 0;
}
