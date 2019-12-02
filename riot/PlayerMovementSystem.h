#pragma once

#include <vector>

#include "system.h"
#include "physics.h"
#include "manager.h"

namespace System {

	class PlayerMovementSystem : ECS::System {
		public:
			void initialize(ECS::Manager* manager);

			void update(float frameTime);
		};

}