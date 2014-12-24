#ifndef COSMOCELL_APP_TEST_LAYER_GRAPHIC
#define COSMOCELL_APP_TEST_LAYER_GRAPHIC

#include "base.hpp"

namespace cosmocell
{
    namespace layer
    {
        namespace test
        {
            class graphic : public base
            {
            protected:
                // Test window handle.
                cosmodon::window m_window;

            public:
                /**
                 * Constructor.
                 */
                graphic();

                /**
                 * Prepare graphic test.
                 */
                virtual void prepare();

                /**
                 * Perform graphic test.
                 */
                virtual bool execute();
            };
        }
    }
}

#endif
