#pragma once

#include <vector>

#include "system.h"
#include "manager.h"
#include "attack.h"

namespace System {

	class PlayerAttackSystem : public ECS::System {
		public:
			void initialize(ECS::Manager* manager);

			void update(float frameTime);
		};

}

