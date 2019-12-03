#pragma once

#include <vector>

#include "system.h"
#include "manager.h"

namespace System {

	class DamageSystem : public ECS::System {
	public:
		void update();
	};

}