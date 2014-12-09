#include <cosmodon/cosmodon.hpp>
#include <test/layer.hpp>

using namespace cosmocell;

int main()
{
    try {
        // Prepare testing program.
        test::layer::root *program = new test::layer::root;
        engine cosmodon_engine(program);

        // Perform tests.
        cosmodon_engine.execute();
    }

    // Catch errors.
    catch(exception::error &e) {
        debug("error", e.what());
        return 1;
    }
    
    // Catch fatal errors.
    catch(exception::fatal &e) {
        debug("fatal", e.what());
        return 1;
    }
    return 0;
}
