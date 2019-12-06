#pragma once

#include "Manager.h"
#include "Entity.h"
#include "System.h"
#include "PlayerEntity.h"
#include "PositionComponent.h"
#include "GameStateComponent.h"
#include "GameStateComponent.h"

namespace System {

	class Camera : public ECS::System {
	public:
		void update(float frameTime);
	};

}
