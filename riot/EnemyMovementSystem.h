#pragma once

#include <vector>
#include <unordered_set>
#include <forward_list>

#include "System.h"
#include "Entity.h"
#include "typeUtil.h"
#include "BlockerEntity.h"
#include "GuardEntity.h"
#include "EliteGuardEntity.h"
#include "EliteSoldierEntity.h"
#include "WallEntity.h"
#include "PositionComponent.h"
#include "CollidableComponent.h"
#include "enemyUtil.h"

namespace System {

	class EnemyMovement : public ECS::System {
	public:
		void update(float frameTime);
	};

}
