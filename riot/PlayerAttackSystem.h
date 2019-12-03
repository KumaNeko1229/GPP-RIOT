#pragma once

#include <vector>
#include <unordered_map>

#include "system.h"
#include "manager.h"
#include "attack.h"
#include "bullet.h"
#include "Player.h"
#include "Entity.h"

namespace System {

	class PlayerAttackSystem : public ECS::System {
		public:
			void update(float frameTime);
		};

}

