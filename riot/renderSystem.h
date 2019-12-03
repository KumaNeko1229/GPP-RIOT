#pragma once

#include <vector>

#include "texture.h"
#include "transform.h"
#include "position.h"
#include "system.h"
#include "manager.h"

namespace System {

class RenderSystem : public ECS::System {
	public:
		void update(float frameTime);

		void render();

		void releaseAll();

		void resetAll();
};

}
