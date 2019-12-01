#pragma once

#include <vector>

#include "system.h"
#include "manager.h"

namespace System {

	class DamageSystem : ECS::System {
	public:
		void initialize(ECS::Manager* manager);

		void processDamage(ECS::Entity* entity, int damage);
	};

}