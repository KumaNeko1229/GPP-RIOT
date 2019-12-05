#pragma once

#include "System.h"
#include "Manager.h"
#include "ButtonEntity.h"
#include "PauseEntity.h"
#include "PlayerEntity.h"
#include "ClickableComponent.h"

namespace System {

	class Click : public ECS::System {

	public:
		void update();

	};

}
