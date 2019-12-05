#pragma once

#include <vector>
#include <unordered_map>

#include "Attack.h"
#include "EliteSoldier.h"
#include "system.h"
#include "manager.h"
#include "EliteGuard.h"
#include "Guard.h"
#include "Entity.h"
#include "Player.h"
#include "Blocker.h"
#include "MetalBullet.h"
#include "RubberBullet.h"

namespace System {

	class EnemyAttackSystem : public ECS::System {
	public:
		void update(float frameTime);
	};

}