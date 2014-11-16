#ifndef COSMO_CLIENT_LAYER_WORLD
#define COSMO_CLIENT_LAYER_WORLD

#include <vector>
#include <irrlicht.h>

#include <core/component.hpp>
#include <core/layer.hpp>
#include <core/network.hpp>
#include <game/character.hpp>
#include <core/report.hpp>

namespace cosmo
{
    namespace layer
    {
        class world : public layer::base
        {
        protected:
            // Collection of models.
            std::vector<core::component::model*> m_models;

            // Network socket.
            network::socket* m_socket_in;
            network::socket* m_socket_out;

            // Layer reporter.
            core::report m_reporter;

        public:
            // Constructor.
            world(irr::video::IVideoDriver* driver, irr::scene::ISceneManager* scene_manager,
              zmq::context_t* context);

            // Perform a layer tick.
            virtual bool tick();
        };
    }
}

#endif
