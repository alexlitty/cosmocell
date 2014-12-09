#include <limits>
#include <test/layer.hpp>

using namespace cosmodon;
using namespace cosmocell;

test::layer::network_accuracy::network_accuracy(network::context *context)
{
    // Prepare sockets.
    m_alpha = context->create(network::socket::REQUEST);
    m_beta = context->create(network::socket::REPLY);

    m_beta->connect(network::endpoint("127.0.0.1", "54321"));
    m_alpha->bind(network::endpoint("127.0.0.1", "54321"));

    m_timer = time(nullptr);
}

test::layer::network_accuracy::~network_accuracy()
{
    delete m_alpha;
    delete m_beta;
}

// Sends a message over one socket, and verifies another local socket receives it successfully.
bool test::layer::network_accuracy::send_and_verify(network::buffer &data, network::socket *out, network::socket *in)
{
    static network::buffer transferred_data;

    // Send data.
    if (!out->send(data)) {
        std::cout << " - Sending data failed." << std::endl;
        return false;
    }

    // Receive data.
    for (unsigned int i = 0; !in->receive(transferred_data); i++) {
        if (i == 10000) {
            std::cout << " - Receiving data failed." << std::endl;
            return false;
        }
    }

    // Verify data.
    if (transferred_data != data) {
        std::cout << " - Data comparison failed." << std::endl;
        return false;
    }
    return true;
}

bool test::layer::network_accuracy::tick()
{
    static uint16_t sample_data = 0;
    network::buffer buff;

    // Prepare buffer.
    buff.clear();
    sample_data += 2;
    buff.write(sample_data);

    // Perform one-way test.
    if (!send_and_verify(buff, m_alpha, m_beta)) {
        return false;
    }

    // Reset buffer with new data.
    buff.clear();
    sample_data += 2;
    buff.write(sample_data);

    // Perform round-trip test.
    if (!send_and_verify(buff, m_beta, m_alpha)) {
        return false;
    }
    
    // Continue test, informing status.
    if (sample_data != 0) {
        std::cout << "\r - " << (sample_data / 2) << " / " << ((std::numeric_limits<uint16_t>::max() / 2) - 1) << " messages sent, received and verified." << std::flush;
        return true;
    }

    // End test.
    std::cout << std::endl << " - Network Buffers are operational on this machine." << std::endl;
    return false;
}

// Prints introductory message.
void test::layer::network_accuracy::intro() const
{
    std::cout << std::endl << "Measuring network accuracy..." << std::endl;
}
