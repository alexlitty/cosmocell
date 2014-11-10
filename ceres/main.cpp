#define COSMO_APP_NAME "ceres"

#include <core/network.hpp>

using namespace cosmo;

int main()
{
    try {
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
    }
    return 0;
}
