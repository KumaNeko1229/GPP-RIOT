#pragma once

#include <vector>
#include <unordered_map>

#include "System.h"
#include "Manager.h"
#include "Entity.h"
#include "AttackComponent.h"
#include "EliteSoldierEntity.h"
#include "MetalBulletEntity.h"
#include "PlayerEntity.h"

namespace System {

	class EliteSoldierAttack : public ECS::System {
	public:
		void update(float frameTime);
	};

}