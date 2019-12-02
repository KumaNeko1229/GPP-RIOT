#pragma once

#include <vector>

#include "system.h"
#include "manager.h"
#include "attack.h"

namespace System {

	class PlayerAttackSystem : public ECS::System {
		public:
			void initialize(ECS::Manager* manager, Graphics* graphics, Input* input);

			void update(float frameTime);
		};

}

