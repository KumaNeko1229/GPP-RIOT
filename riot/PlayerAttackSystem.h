#pragma once

#include <vector>
#include <unordered_map>

#include "System.h"
#include "Manager.h"
#include "Entity.h"
#include "BulletEntity.h"
#include "PlayerEntity.h"
#include "AttackComponent.h"

namespace System {

	class PlayerAttack : public ECS::System {
		public:
			void update(float frameTime);
		};

}

