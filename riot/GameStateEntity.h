#pragma once

#include "Entity.h"
#include "Manager.h"
#include "GameStateComponent.h"

namespace Entity {

	class GameState : ECS::Entity {};

	ECS::EntityIdType createGameState(ECS::Manager* manager);
}
