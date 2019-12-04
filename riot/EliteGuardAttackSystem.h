#pragma once

#include <vector>
#include <unordered_map>

#include "Attack.h"
#include "EliteGuard.h"
#include "system.h"
#include "manager.h"
#include "RubberBullet.h"
#include "Entity.h"
#include "Player.h"

namespace System {

	class EliteGuardAttackSystem : public ECS::System {
	public:
		void update(float frameTime);
	};

}