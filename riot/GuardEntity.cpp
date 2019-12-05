#include "GuardEntity.h"

namespace Entity {

	ECS::EntityIdType createGuardEntity(ECS::Manager* manager, Graphics* graphics, int x, int y) {
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

		Component::Attack attackComponent = Component::Attack();
		attackComponent.attackDelay = 0.4f;
		attackComponent.interval = 1;
		Component::Damage damageComponent = Component::Damage();
		damageComponent.health = 45;

		Component::Position positionComponent = Component::Position();
		positionComponent.x = x * tileWidth;
		positionComponent.y = y * tileHeight;

		// Add the components
		manager->addComponent(guardId, textureComponent);
		manager->addComponent(guardId, transformComponent);
		manager->addComponent(guardId, attackComponent);
		manager->addComponent(guardId, damageComponent);
		manager->addComponent(guardId, positionComponent);

		return guardId;
	}
}