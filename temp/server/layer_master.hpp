#ifndef COSMO_SERVER_LAYER_MASTER
#define COSMO_SERVER_LAYER_MASTER

#include <vector>
#include <irrlicht.h>
#include <core/component.hpp>
#include <core/layer.hpp>
#include <core/report.hpp>
#include <core/network.hpp>

namespace cosmo
{
    namespace layer
    {
        class master : public base
        {
        protected:
            // Network sockets.
            network::socket* m_socket_in;
            network::socket* m_socket_out;

            // Network messages.
            network::message::base* m_message_ping;

            // Reporter storage.
            core::report m_reporter;

            // Collection of players.
            std::vector<core::component::model*> m_players;

        public:
            // Constructor.
            master(irr::video::IVideoDriver* driver, irr::scene::ISceneManager* scene_manager,
              zmq::context_t* context);

            // Perform a layer tick.
            virtual bool tick();
        };
    }
}

#endif
