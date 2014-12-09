#define COSMODON_APP_NAME "ceres"

#include <cosmodon.hpp>
#include <ctime>
#include <iomanip>

using namespace cosmodon;

class layer_route : public layer::base
{
protected:
    network::socket *in;
    network::socket *out;
    time_t timer;

public:
    // Initialize routing.
    void init()
    {
       in = m_net->create(network::socket::PAIR);
       out = m_net->create(network::socket::PAIR);
       
       in->bind(network::endpoint("127.0.0.1", network::PORT::INTERNAL));
       out->connect(network::endpoint("127.0.0.1", network::PORT::INTERNAL));

       timer = time(nullptr);
    }

    // Perform routing.
    bool tick()
    {
        static network::message *test_msg;
        static network::frame::data *test_frame;
        static network::message receiver;
        static unsigned long long int x = 99;

        // Send message.
        test_msg = new network::message;
        test_frame = new network::frame::data(&x, sizeof(x));
        test_msg->add(test_frame);
        if (!out->send(test_msg)) {
            debug("network", "Failed to send message");
        }
        delete test_msg;

        // Receive message.
        while (in->receive(receiver)) {
        }

        // Output statistics.
        if (time(nullptr) - timer >= 1) {
            std::cout << "\r[stat] ";

            std::cout << "Sent " << out->transferred() << " @ " << out->rate()
                      << " / Received " << in->transferred() << " @ " << in->rate();

            std::cout.flush();
            timer = time(nullptr);
        }

        return true;
    }
};

int main()
{
    try {
        // Start Cosmodon.
        layer_route *root = new layer_route;
        engine ceres(root);
        root->init();
        ceres.execute();
    }

    // Catch errors.
    catch (exception::fatal &e) {
        debug("fatal", e.what());
        return 1;
    }
    return 0;
}
