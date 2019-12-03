#pragma once

#include <vector>
#include <unordered_set>

#include "system.h"
#include "physics.h"
#include "manager.h"
#include "position.h"
#include "Player.h"

namespace System {

	class PlayerMovementSystem : public ECS::System {
		public:
			void update(float frameTime);
		};

}