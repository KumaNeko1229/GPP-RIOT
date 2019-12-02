#include "texture.h"
#include "system.h"
#include "manager.h"
#include "textDX.h"
#include <string>
#include "Text.h"
#include "Button.h"

namespace System {

	class TextSystem : ECS::System {

	public:
		void initialize(ECS::Manager* manager, Graphics* graphics);

		void update(float frameTime);

		void render();

		void releaseAll();

		void resetAll();
	};

}
