#include "GameStateEntity.h"

namespace Entity {
	ECS::EntityIdType createGameState(ECS::Manager* manager) {
		ECS::EntityIdType entityId = manager->createEntity<GameState>();

		Component::GameState gameStateComponent;
		gameStateComponent.renderRect.top = 0;
		gameStateComponent.renderRect.left = 0;
		gameStateComponent.renderRect.bottom = GAME_HEIGHT;
		gameStateComponent.renderRect.right = GAME_WIDTH;

		manager->addComponent<Component::GameState>(entityId, gameStateComponent);

		return entityId;
	}
}
