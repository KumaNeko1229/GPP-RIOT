#pragma once

#include <vector>

#include "system.h"
#include "manager.h"
#include "Physics.h"
#include "Position.h"

namespace System {

	class MovementSystem : public ECS::System {
		public:
			void update(float frameTime);
		};

}
