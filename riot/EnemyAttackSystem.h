#pragma once

#include <vector>
#include <unordered_map>

#include "Entity.h"
#include "System.h"
#include "Manager.h"
#include "AttackComponent.h"
#include "EliteSoldierEntity.h"
#include "EliteGuardEntity.h"
#include "GuardEntity.h"
#include "PlayerEntity.h"
#include "BlockerEntity.h"
#include "MetalBulletEntity.h"
#include "RubberBulletEntity.h"

namespace System {

	class EnemyAttack : public ECS::System {
	public:
		void update(float frameTime);
	};

}