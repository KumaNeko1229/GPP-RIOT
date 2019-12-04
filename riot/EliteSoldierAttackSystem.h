#pragma once

#include <vector>
#include <unordered_map>

#include "Attack.h"
#include "EliteSoldier.h"
#include "system.h"
#include "manager.h"
#include "bullet.h"
#include "Entity.h"

namespace System {

	class EliteSoldierAttackSystem: public ECS::System {
	public:
		void update(float frameTime);
	};

}