#pragma once

#include <vector>

#include "system.h"
#include "manager.h"

namespace System {

	class MovementSystem : public ECS::System {
		public:
			void initialize(ECS::Manager* manager, Graphics* graphics, Input* input);

			void update(float frameTime);
		};

}
