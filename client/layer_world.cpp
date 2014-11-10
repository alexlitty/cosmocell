#include <irrlicht.h>
#include <client/layer_world.hpp>

using namespace cosmo;

// Constructor.
layer::world::world(irr::video::IVideoDriver* driver, irr::scene::ISceneManager* scene_manager,
  zmq::context_t* context)
  : layer::base(driver, scene_manager, context)
{
    std::string server = network::endpoint("alexlitty.com");

    // Initialize socket.
    m_socket_in = new network::socket_subscribe(context);

    // Initialize connections.
    m_reporter.msg("Establishing Connection: ", "network", false);
    m_reporter.raw(server);
    m_socket_in->connect(network::endpoint("alexlitty.com"));
    m_reporter.msg("Connection Established", "network");

    // Add player model.
    game::character* player = new game::character(m_scene_root, m_scene_manager);
    m_models.push_back(player);

    // Temporary: Animate player model.
    irr::scene::ISceneNodeAnimator* animation_test = m_scene_manager->createRotationAnimator(
        irr::core::vector3df(0.8f, 0, 0.8f)
        );
    player->addAnimator(animation_test);

    // Drop references.
    animation_test->drop();
    player->drop();
}

bool layer::world::tick()
{
    network::message::base* test_message;
    if (m_socket_in->receive(test_message)) {
        m_reporter.msg("Received Ping");
    }
    return true;
}
