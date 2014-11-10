#include <server/layer_master.hpp>

using namespace cosmo;

layer::master::master(irr::video::IVideoDriver* driver,
  irr::scene::ISceneManager* scene_manager,
  zmq::context_t* context)
  : layer::base(driver, scene_manager, context)
{
    const char* bind_address = network::endpoint("*");

    // Initialize Socket
    m_socket_out = new network::socket_publish(m_context);

    // Initialize Binding
    m_reporter.msg("Binding: ", "network", false);
    m_reporter.raw(bind_address);
    m_socket_out->bind(bind_address);
    m_reporter.msg("Server Binded");
}

bool layer::master::tick()
{
    network::message::base* message_ping;
    static unsigned int i = 250600;

    if (i-- == 0) {
        i = 250600;

        // Send Ping
        message_ping = new network::message::ping;
        if (m_socket_out->send(message_ping)) {
            m_reporter.msg("Ping Sent", "network");
        } else {
            m_reporter.msg("EAGAIN occured while Sending Ping", "network");
        }
    }
    return true;
}
