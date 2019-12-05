#pragma once

#include <vector>
#include <unordered_map>

#include "Manager.h"
#include "Entity.h"
#include "System.h"
#include "BlockerEntity.h"
#include "AttackComponent.h"


namespace System {

	class BlockerAttack : public ECS::System {
	public:
		void update(float frameTime);
	};

}