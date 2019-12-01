#pragma once

#include <vector>

#include "system.h"
#include "manager.h"

namespace System {

	class MovementSystem : ECS::System {
		public:
			void initialize(ECS::Manager* manager);
		};

}
