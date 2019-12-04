#pragma once

#include "system.h"
#include "TearGas.h"
#include "Life.h"

namespace System {

	class ReaperSystem : public ECS::System {
	public:
		void update(float frameTime);
	};

}

