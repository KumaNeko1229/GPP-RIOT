#pragma once

#include "Entity.h"
#include "Manager.h"
#include "GameStateComponent.h"
#include "PositionComponent.h"

namespace Entity {

	class GameState : ECS::Entity {};

	ECS::EntityIdType createGameState(ECS::Manager* manager);
}
