#include "Blocker.h"

namespace Entity {

	ECS::EntityIdType createBlockerEntity(ECS::Manager* manager, Graphics* graphics, int x, int y) {
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

		Component::Attack attackComponent = Component::Attack();
		attackComponent.attackDelay = 0.5;
		attackComponent.interval = 1;
		Component::Damage damageComponent = Component::Damage();
		damageComponent.health = 40;

		Component::Position positionComponent = Component::Position();
		positionComponent.x = x * tileWidth;
		positionComponent.y = y * tileHeight;

		// Add the components
		manager->addComponent(blockerId, textureComponent);
		manager->addComponent(blockerId, transformComponent);
		manager->addComponent(blockerId, attackComponent);
		manager->addComponent(blockerId, damageComponent);
		manager->addComponent(blockerId, positionComponent);

		return blockerId;
	}
}