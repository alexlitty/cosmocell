#include <core/event.hpp>
#include <core/system.hpp>
#include <core/component.hpp>
#include <core/report.hpp>
#include <core/network.hpp>

#include <client/layer_world.hpp>

using namespace cosmo;

int main()
{
    // Prepare irrlicht.
    irr::IrrlichtDevice* irrlicht;
    irr::video::IVideoDriver* driver;
    irr::scene::ISceneManager* scene_manager;

    // Client-specific reporter.
    core::report client_reporter;
    client_reporter.msg("Starting Client");

    try {
        // Create network context.
        zmq::context_t* network_context = new zmq::context_t;

        // Create device.
        irrlicht = irr::createDevice(
            //irr::video::EDT_SOFTWARE,
            irr::video::EDT_NULL,
            irr::core::dimension2d<irr::u32>(640, 480),
            16, false, false, false,
            new core::event::receiver
            );

        // Ensure device initialized.
        if (!irrlicht) {
            throw new exception::fatal("Failed to initialize device");
        }
        
        // Prepare other Irrlicht features.
        irrlicht->setWindowCaption(L"Cosmodon");
        scene_manager = irrlicht->getSceneManager();
        driver = irrlicht->getVideoDriver();
        
        // Temporary Camera.
        scene_manager->addCameraSceneNode(0,
            irr::core::vector3df(0,30,-40),
            irr::core::vector3df(0,5,0)
            );

        // Create the first layer.
        layer::base* layer_root = new layer::world(
            driver,
            irrlicht->getSceneManager(),
            network_context
            );

        cosmo::core::system client(irrlicht, layer_root);
        client.execute();
    }

    catch (exception::fatal &e) {
        client_reporter.msg(e.getMessage(), "fatal");
    }

    catch (exception::network &e) {
        client_reporter.msg(e.getMessage(), "network error");
    }

    return 0;
}
