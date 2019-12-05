#include "GameStateSystem.h"

namespace System {

	void GameState::initialize(ECS::Manager* manager, Graphics* graphics, Input* input) {
		System::initialize(manager, graphics, input);

		// Create the game state entity
		this->gameStateId = Entity::createGameState(manager);
	}

	void GameState::update(float frameTime) {

	}

	void GameState::releaseAll() {
		this->manager->removeEntity<Entity::GameState>(this->gameStateId);
	}
}
