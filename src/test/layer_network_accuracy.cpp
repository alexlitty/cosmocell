#include <limits>
#include <test/layer.hpp>

using namespace cosmodon;
using namespace cosmocell;

test::layer::network_accuracy::network_accuracy() : m_socket(54321)
{
    m_timer = time(nullptr);
}

test::layer::network_accuracy::~network_accuracy()
{

}

bool test::layer::network_accuracy::tick()
{
    static uint16_t sample_data = 0;
    network::buffer buff;
    std::string address;

    // Prepare buffer.
    buff.clear();
    sample_data += 2;
    buff.write(sample_data);

    // Send sample data, wait a short time.
    address = "127.0.0.1";
    if (!m_socket.send(address, buff)) {
        std::cout << std::endl << " - Data could not be sent." << std::endl;
        return false;
    }
    usleep(100);

    // Wait for sample data.
    for (uint16_t i = 0; !m_socket.receive(address, buff); i++) {
        if (i == 10000) {
            std::cout << " - Data could not be received." << std::endl;
            return false;
        }
    }

    // Continue test, informing status.
    if (sample_data != 0) {
        std::cout << "\r - " << (sample_data / 2) << " / " << ((std::numeric_limits<uint16_t>::max() / 2) - 1) << " messages sent, received and verified." << std::flush;
        return true;
    }

    // End test.
    std::cout << std::endl << " - Network Buffers are operational." << std::endl;
    return false;
}

// Prints introductory message.
void test::layer::network_accuracy::intro() const
{
    std::cout << std::endl << "Measuring network accuracy..." << std::endl;
}
