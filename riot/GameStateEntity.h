#pragma once

#include "Entity.h"
#include "Manager.h"
#include "GameStateComponent.h"
#include "PositionComponent.h"

#include <string>
#include <fstream>
#include <codecvt>

namespace Entity {

	class GameState : ECS::Entity {};

	ECS::EntityIdType createGameState(ECS::Manager* manager);

	void updateCamera(ECS::Manager* manager, ECS::EntityIdType);
}
