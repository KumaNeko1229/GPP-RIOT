#pragma once

#include <vector>
#include <unordered_map>

#include "Entity.h"
#include "System.h"
#include "Manager.h"
#include "AttackComponent.h"
#include "EliteGuardEntity.h"
#include "RubberBulletEntity.h"
#include "PlayerEntity.h"

namespace System {

	class EliteGuardAttack : public ECS::System {
	public:
		void update(float frameTime);
	};

}