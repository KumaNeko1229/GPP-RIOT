#pragma once

#include <vector>
#include <unordered_map>

#include "Entity.h"
#include "System.h"
#include "Manager.h"
#include "GuardEntity.h"
#include "RubberBulletEntity.h"
#include "PlayerEntity.h"
#include "AttackComponent.h"

namespace System {

	class GuardAttack : public ECS::System {
	public:
		void update(float frameTime);
	};

}