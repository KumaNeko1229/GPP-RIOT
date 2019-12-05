#pragma once

#include <vector>

#include "Texture.h"
#include "Transform.h"
#include "Position.h"
#include "System.h"
#include "Manager.h"

namespace System {

class RenderSystem : public ECS::System {
	public:
		void render();

		void releaseAll();

		void resetAll();
};

}
