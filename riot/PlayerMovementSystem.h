#pragma once

#include <vector>

#include "system.h"
#include "physics.h"
#include "manager.h"
#include "position.h"

namespace System {

	class PlayerMovementSystem : public ECS::System {
		public:
			void initialize(ECS::Manager* manager);

			void update(float frameTime);

			void render();

			void releaseAll();

			void resetAll();
		};

}