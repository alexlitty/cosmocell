#include <cosmodon/cosmodon.hpp>
#include <test/layer.hpp>

using namespace cosmocell;

int main()
{
    try {
        // Prepare testing program.
        cosmodon::layer *program = new layer::test::root;
        cosmodon::engine cosmodon_engine(program);

        // Perform tests.
        cosmodon_engine.execute();
    }

    // Catch errors.
    catch(const cosmodon::exception::base &e) {
        std::cout << std::endl << "[error] " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
