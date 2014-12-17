#include <test/layer.hpp>

// Prepare buffer testing.
void cosmocell::layer::test::buffer::prepare()
{
    std::cout << "Testing buffers..." << std::endl;
}

// Perform buffer testing.
bool cosmocell::layer::test::buffer::execute()
{
    uint8_t sample_int;
    std::string sample_string;

    // Perform all tests.
    try {
        // Initial size.
        if (m_buffer.length() != 0) {
            throw cosmodon::exception::error("Initialized buffer size is not zero."); 
        }

        // Write integers.
        try {
            sample_int = 0;
            for (uint8_t i = 0; i < 20; i++) {
                m_buffer << sample_int;
                sample_int += 6;
            }
        } catch (const cosmodon::exception::overflow &e) {
            throw cosmodon::exception::error("Buffer overflow while writing integers.");
        }

        // Read integers.
        try {
            for (uint8_t i = 0; i < 20; i++) {
                m_buffer >> sample_int;
                if (sample_int != i * 6) {
                    throw cosmodon::exception::error("Integer data lost integrity.");
                }
            }
        } catch (const cosmodon::exception::overflow &e) {
            throw cosmodon::exception::error("Buffer overflow while reading integers.");
        }

        // Write strings.
        m_buffer.clear();
        try {
            sample_string = "test";
            m_buffer << sample_string;
            sample_string = "";
            m_buffer << sample_string;
            sample_string = "1234567890abcdefgh";
            m_buffer << sample_string;
        } catch (const cosmodon::exception::overflow &e) {
            throw cosmodon::exception::error("Buffer overflow while writing strings.");
        }

        // Read strings.
        try {
            std::string explain;

            m_buffer >> sample_string;
            if (sample_string != "test") {
                throw cosmodon::exception::error("Short string data lost integrity. " + explain);
            }
            
            m_buffer >> sample_string;
            if (sample_string != "") {
                throw cosmodon::exception::error("Empty string data lost integrity.");
            }

            m_buffer >> sample_string;
            if (sample_string != "1234567890abcdefgh") {
                throw cosmodon::exception::error("Long string data lost integrity.");
            }
        } catch (const cosmodon::exception::overflow &e) {
            throw cosmodon::exception::error("Buffer overflow while reading strings.");
        }
    }

    // Catch errors.
    catch (const cosmodon::exception::error &e) {
        std::cout << " - " << e.what() << std::endl;
        return false;
    }
    std::cout << " - Buffer tests successful." << std::endl;
    return false;
}
