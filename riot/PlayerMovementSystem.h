#pragma once

#include <vector>
#include <unordered_set>

#include "System.h"
#include "Manager.h"
#include "PlayerEntity.h"
#include "PhysicsComponent.h"
#include "PositionComponent.h"

namespace System {

	class PlayerMovement : public ECS::System {
		public:
			void update(float frameTime);
		};

}