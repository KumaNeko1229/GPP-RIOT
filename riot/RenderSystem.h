#pragma once

#include <vector>

#include "System.h"
#include "Manager.h"
#include "TextureComponent.h"
#include "TransformComponent.h"
#include "PositionComponent.h"

namespace System {

class Render : public ECS::System {
	public:
		void render();

		void releaseAll();

		void resetAll();
};

}
