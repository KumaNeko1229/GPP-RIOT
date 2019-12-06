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

	void updateCamera(ECS::Manager* manager, ECS::EntityIdType id) {
		Component::Position position = manager->getEntityComponent<Component::Position>(id);

		std::wstring level;
		std::ifstream map;
		map.open("map.txt");
		while (map)
		{
			std::string line;
			std::getline(map, line);
			std::wstring wLine = std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(line);
			level += wLine;
		}

	}
}
