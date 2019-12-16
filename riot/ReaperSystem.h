#pragma once

#include "System.h"
#include "LifeComponent.h"
#include "TearGasEntity.h"
#include "GameStateComponent.h"

namespace System {

	class Reaper : public ECS::System {
	public:
		void update(float frameTime);
	};

}

