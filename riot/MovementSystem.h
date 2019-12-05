#pragma once

#include <vector>

#include "System.h"
#include "Manager.h"
#include "PhysicsComponent.h"
#include "PositionComponent.h"
#include "TearGasEntity.h"

namespace System {

	class Movement : public ECS::System {
		public:
			void update(float frameTime);
		};

}
