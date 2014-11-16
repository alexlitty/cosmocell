#include <core/system.hpp>
#include <core/component.hpp>
#include <core/report.hpp>
#include <server/layer_master.hpp>

using namespace cosmo;

int main()
{
    irr::IrrlichtDevice* irrlicht;
    irr::video::IVideoDriver* driver;
    irr::scene::ISceneManager* scene_manager;
    zmq::context_t* network_context;

    core::report server_reporter;

    try {
        // Start networking context.
        network_context = new zmq::context_t;

        // Create device without graphics.
        irrlicht = irr::createDevice(irr::video::EDT_NULL);

        // Ensure device initialized.
        if (!irrlicht) {
            throw new exception::fatal("Failed to initialize device.");
        }
        
        // Prepare other Irrlicht features.
        scene_manager = irrlicht->getSceneManager();

        // Create the first layer.
        layer::base* layer_root = new layer::master(
            driver, irrlicht->getSceneManager(),
            network_context
            );

        cosmo::core::system server(irrlicht, layer_root);
        server.execute();
    }

    catch (exception::error &e) {
        server_reporter.msg(e.getMessage());
    }

    catch (exception::fatal) {
        return 1;
    }

    return 0;
}
