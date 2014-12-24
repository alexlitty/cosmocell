#include <limits>
#include <test/layer/network_accuracy.hpp>

// Network accuracy test constructor.
cosmocell::layer::test::network_accuracy::network_accuracy() : m_socket(54321)
{

}

// Prepares network accuracy test.
void cosmocell::layer::test::network_accuracy::prepare()
{
    std::cout << std::endl << "Measuring network accuracy..." << std::endl;
}

// Performs network accuracy test.
bool cosmocell::layer::test::network_accuracy::execute()
{
    static uint8_t sample_data = 0;
    std::string address;

    // Prepare buffer.
    sample_data +=2;
    m_buffer.clear();
    m_buffer << sample_data;

    // Send sample data.
    address = "127.0.0.1";
    if (!m_socket.send(m_buffer, address)) {
        std::cout << std::endl << " - Some data could not be sent." << std::endl;
        return false;
    }

    // Receive sample data.
    m_timer.reset();
    while (!m_socket.receive(m_buffer, address)) {
        if (m_timer.elapsed() > 1) {
            std::cout << " - Some data could not be received." << std::endl;
            return false;
        }
        ::usleep(100);
    }

    // Check source address.
    if (address != "127.0.0.1") {
        std::cout << " - Socket address lost in transfer." << std::endl;
        return false;
    }

    // Continue test, informing status.
    if (sample_data != 0) {
        std::cout << "\r - " << (sample_data / 2) << " / " << ((std::numeric_limits<uint8_t>::max() / 2)) << " messages sent, received and verified." << std::flush;
        return true;
    }

    // End test.
    std::cout << std::endl << " - Cosmodon sockets are sending accurately." << std::endl;
    return false;
}
