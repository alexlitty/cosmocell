#ifndef COSMO_GAME_CHARACTER
#define COSMO_GAME_CHARACTER

#include <irrlicht.h>
#include <core/component.hpp>

namespace cosmo
{
    namespace game
    {
        class character : public core::component::model
        {
            // Vertex list.
            irr::video::S3DVertex m_vertices[4];

            // Model material.
            irr::video::SMaterial m_material;

        public:
            // Constructor.
            character(irr::scene::ISceneNode* parent, irr::scene::ISceneManager* scene_manager, irr::s32 id = 0)
              : core::component::model(parent, scene_manager, id)
            {
                m_material.Wireframe = false;
                m_material.Lighting = false;

                m_vertices[0] = irr::video::S3DVertex(0,0,10, 1,1,0,
                    irr::video::SColor(255,0,255,255), 0, 1);
                m_vertices[1] = irr::video::S3DVertex(10,0,-10, 1,0,0,
                    irr::video::SColor(255,255,0,255), 1, 1);
                m_vertices[2] = irr::video::S3DVertex(0,20,0, 0,1,1,
                    irr::video::SColor(255,255,255,0), 1, 0);
                m_vertices[3] = irr::video::S3DVertex(-10,0,-10, 0,0,1,
                    irr::video::SColor(255,0,255,0), 0, 0);
                
                m_bounding_box.reset(m_vertices[0].Pos);
                for (irr::s32 i=1; i<4; ++i)
                    m_bounding_box.addInternalPoint(m_vertices[i].Pos);
            }

            // Render.
            virtual void render()
            {
                irr::u16 indices[] = {   0,2,3, 2,1,3, 1,0,3, 2,0,1  };
                irr::video::IVideoDriver* driver = SceneManager->getVideoDriver();

                driver->setMaterial(m_material);
                driver->setTransform(irr::video::ETS_WORLD, AbsoluteTransformation);
                driver->drawVertexPrimitiveList(&m_vertices[0], 4, &indices[0], 4,
                    irr::video::EVT_STANDARD, irr::scene::EPT_TRIANGLES, irr::video::EIT_16BIT);
            }

            // 
            virtual irr::u32 getMaterialCount() const { return 1; }
            virtual irr::video::SMaterial& getMaterial(irr::u32 i)
            {
                return m_material;
            }

            virtual void OnRegisterSceneNode()
            {
                if (IsVisible)
                    SceneManager->registerNodeForRendering(this);

                ISceneNode::OnRegisterSceneNode();
            }
        };
    }
}

#endif
