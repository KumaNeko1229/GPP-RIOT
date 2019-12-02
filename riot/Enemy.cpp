#include "Enemy.h";

namespace Entity {

	ECS::EntityIdType createBlockerEntity(ECS::Manager* manager, Graphics* graphics) {
		ECS::EntityIdType blockerId = manager->createEntity<Blocker>();
		// Create the components
		// Create texture Component
		Component::Texture textureComponent = Component::Texture();
		if (!textureComponent.loadTexture(graphics, ENEMY_IMAGE))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading blocker entity texture"));
		}
		textureComponent.visible = true;

		// Create transform component
		Component::Transform transformComponent = Component::Transform();

		// Add the components
		manager->addComponent(blockerId, textureComponent);
		manager->addComponent(blockerId, transformComponent);

		return blockerId;
	}

	ECS::EntityIdType createGuardEntity(ECS::Manager* manager, Graphics* graphics) {
		ECS::EntityIdType guardId = manager->createEntity<Guard>();
		// Create the components
		// Create texture Component
		Component::Texture textureComponent = Component::Texture();
		if (!textureComponent.loadTexture(graphics, ENEMY_IMAGE))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading guard entity texture"));
		}
		textureComponent.visible = true;

		// Create transform component
		Component::Transform transformComponent = Component::Transform();

		// Add the components
		manager->addComponent(guardId, textureComponent);
		manager->addComponent(guardId, transformComponent);

		return guardId;
	}

	ECS::EntityIdType createEliteGuardEntity(ECS::Manager* manager, Graphics* graphics) {
		ECS::EntityIdType eliteGuardId = manager->createEntity<EliteGuard>();
		// Create the components
		// Create texture Component
		Component::Texture textureComponent = Component::Texture();
		if (!textureComponent.loadTexture(graphics, ENEMY_IMAGE))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading elite guard entity texture"));
		}
		textureComponent.visible = true;

		// Create transform component
		Component::Transform transformComponent = Component::Transform();

		// Add the components
		manager->addComponent(eliteGuardId, textureComponent);
		manager->addComponent(eliteGuardId, transformComponent);

		return eliteGuardId;
	}

	ECS::EntityIdType createEliteSoldierEntity(ECS::Manager* manager, Graphics* graphics) {
		ECS::EntityIdType eliteSoldierId = manager->createEntity<EliteSoldier>();
		// Create the components
		// Create texture Component
		Component::Texture textureComponent = Component::Texture();
		if (!textureComponent.loadTexture(graphics, ENEMY_IMAGE))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading elite soldier entity texture"));
		}
		textureComponent.visible = true;

		// Create transform component
		Component::Transform transformComponent = Component::Transform();

		// Add the components
		manager->addComponent(eliteSoldierId, textureComponent);
		manager->addComponent(eliteSoldierId, transformComponent);

		return eliteSoldierId;
	}

}