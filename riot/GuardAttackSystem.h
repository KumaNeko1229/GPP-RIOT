#pragma once

#include <vector>
#include <unordered_map>

#include "Attack.h"
#include "Guard.h"
#include "system.h"
#include "manager.h"
#include "RubberBullet.h"
#include "Entity.h"
#include "Player.h"

namespace System {

	class GuardAttackSystem : public ECS::System {
	public:
		void update(float frameTime);
	};

}