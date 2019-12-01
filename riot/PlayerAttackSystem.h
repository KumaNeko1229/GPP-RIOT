#pragma once

#include <vector>

#include "system.h"
#include "manager.h"

namespace System {

	class PlayerAttackSystem : ECS::System {
		public:
			void initialize(ECS::Manager* manager);

			void update();
		};

}

