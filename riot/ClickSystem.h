#pragma once
#include <unordered_set>

#include "System.h"
#include "Manager.h"
#include "ButtonEntity.h"
#include "PauseEntity.h"
#include "PlayerEntity.h"
#include "ClickableComponent.h"
#include "GameStateComponent.h"

namespace System {

	class ClickSystem : public ECS::System {

	public:
		void update(float frametime);

	};

}
