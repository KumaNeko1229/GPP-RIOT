#pragma once

#include <vector>
#include <d3d9.h>

#include "System.h"
#include "Manager.h"
#include "PlayerEntity.h"
#include "TextureComponent.h"
#include "TransformComponent.h"
#include "PositionComponent.h"

namespace System {

	class HUD : public ECS::System {
	public:
		void update(float frameTime);

		void render();

		void releaseAll();

		void resetAll();
	};

}
