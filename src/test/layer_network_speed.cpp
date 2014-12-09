#include <test/layer.hpp>

using namespace cosmocell;

// Initialize layer.
test::layer::network_speed::network_speed(network::context *context)
{
    // Prepare sockets.
    m_in = context->create(network::socket::PAIR);
    m_out = context->create(network::socket::PAIR);

    m_in->bind(network::endpoint("127.0.0.1", "12345"));
    m_out->connect(network::endpoint("127.0.0.1", "12345"));
}

// Destructor.
test::layer::network_speed::~network_speed()
{
    delete m_in;
    delete m_out;
}

// Initiates this test.
void test::layer::network_speed::start()
{
    m_timer = time(nullptr);
}

// Tick the layer.
bool test::layer::network_speed::tick()
{
    static uint64_t count_out = 0, count_in = 0;
    uint64_t x;
    static bool first = true;

    // Start test timer.
    if (first) {
        first = false;
        start();
    }

    // Write to buffer.
    network::buffer data;
    data.write(count_out);
    data.reset();

    // Read from buffer.
    data.read(x);
    data.reset();

    // Send data out to network.
    if (m_out->send(data)) {
        count_out++;
    }
    while (m_in->receive(data)) {
        count_in++;
    }

    // Stop test after three seconds.
    if (time(nullptr) - m_timer >= 5) {
        std::cout << " - Sent " << count_out << " messages @ " << m_out->rate() << std::endl
                  << " - Received " << count_in << " messages @ " << m_in->rate() << std::endl;
        return false;
    }
    return true;
}

// Prints introductory message.
void test::layer::network_speed::intro() const
{
    std::cout << std::endl << "Measuring network performance..." << std::endl;
}
