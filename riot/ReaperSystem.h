#pragma once

#include "system.h"

namespace System {

	class ReaperSystem : public ECS::System {
	public:
		void initialize(ECS::Manager* manager, Graphics* graphics, Input* input);

		void update();

		void destroyEntity(); // used in the update function
	};

}

