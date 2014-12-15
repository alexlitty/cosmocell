#include <test/layer.hpp>

using namespace cosmocell;

// Initialize layer.
test::layer::network_speed::network_speed() : m_socket(12345)
{

}

// Destructor.
test::layer::network_speed::~network_speed()
{

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
    std::string address;

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
    address = "127.0.0.1";
    if (m_socket.send(address, data)) {
        count_out++;
    }
    while (m_socket.receive(address, data)) {
        count_in++;
    }

    // Stop test after three seconds.
    if (time(nullptr) - m_timer >= 5) {
        std::cout << " - Sent " << count_out << " messages @ " << m_socket.rate_out() << std::endl
                  << " - Received " << count_in << " messages @ " << m_socket.rate_in() << std::endl;
        return false;
    }
    return true;
}

// Prints introductory message.
void test::layer::network_speed::intro() const
{
    std::cout << std::endl << "Measuring network performance..." << std::endl;
}
