#pragma once

#include <vector>

#include "system.h"
#include "manager.h"

namespace System {

	class DamageSystem : public ECS::System {
	public:
		void initialize(ECS::Manager* manager, Graphics* graphics, Input* input);

		void processDamage(ECS::Entity* entity, int damage); // called in the update function

		void update();
	};

}