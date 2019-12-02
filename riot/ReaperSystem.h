#pragma once

#include "system.h"

namespace System {

	class ReaperSystem : ECS::System {
	public:
		void initialize(ECS::Manager* manager);

		void update();

		void destroyEntity(); // used in the update function
	};

}

