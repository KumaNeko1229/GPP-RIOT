#pragma once

#include <vector>
#include <unordered_map>

#include "Attack.h"
#include "Blocker.h"
#include "system.h"
#include "manager.h"
#include "Entity.h"


namespace System {

	class BlockerAttackSystem : public ECS::System {
	public:
		void update(float frameTime);
	};

}