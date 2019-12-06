#include "GameStateSystem.h"

namespace System {

	void GameState::initialize(ECS::Manager* manager, Graphics* graphics, Input* input) {
		System::initialize(manager, graphics, input);

		// Create the game state entity
		this->gameStateId = Entity::createGameState(manager);
	}

	void GameState::update(float frameTime) {

		RECT cam;

		std::unordered_set<ECS::EntityIdType>* players = this->manager->getEntities <Entity::Player>();
		RECT &render = this->manager->getEntityComponent<Component::GameState>(this->gameStateId).renderRect;
		
		for (ECS::EntityIdType id : *players) {
			Component::Position playerPos = this->manager->getEntityComponent<Component::Position>(id);
			float offsetX = playerPos.x - (GAME_WIDTH / 2);
			float offsetY = playerPos.y - (GAME_HEIGHT / 2);

			render.left = offsetX;
			render.right = offsetX + GAME_WIDTH;
			render.top = offsetY;
			render.bottom = offsetY + GAME_HEIGHT;

			if (render.left < 0)
			{
				render.left = 0;
				render.right = GAME_WIDTH;
			}

			if (render.right > levelWidth* tileWidth)
			{
				render.right = levelWidth * tileWidth;
				render.left = render.right - GAME_WIDTH;
			}

			if (render.top < 0)
			{
				render.top = 0;
				render.bottom = GAME_HEIGHT;
			}

			if (render.bottom > levelHeight * tileHeight)
			{
				render.bottom = levelHeight * tileHeight;
				render.top = render.bottom - GAME_HEIGHT;
			}
			
		}
	}

	void GameState::releaseAll() {
		this->manager->removeEntity<Entity::GameState>(this->gameStateId);
	}
}
