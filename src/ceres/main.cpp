#define COSMODON_APP_NAME "ceres"

#include <cosmodon.hpp>

using namespace cosmodon;

class layer_route : public layer::base
{
    // Tick.
    bool tick()
    {
        return true;
    }
};

int main()
{
    // Prepare root layer.
    layer::base *layer_root = new layer_route;

    // Start cosmodon.
    engine ceres(layer_route);

    /*try {
        network::start();
        network::socket *internal_in; //, *internal_out, *external_in, *external_out;

        // Prepare test socket.
        internal_in = new network::socket_xsubscribe;
        internal_in->bind(network::endpoint("*", network::port::internal));

        network::message* dummy;

        while (true) {
            if (internal_in->receive(dummy)) {
                debug("main", "Received Message.");
            }
        }
    }
    catch (exception::base &e) {
        debug("error", e.what());
        return 1;
    }*/

    

    return 0;
}
