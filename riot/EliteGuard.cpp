#include "EliteGuard.h"

namespace Entity {

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

		Component::Attack attackComponent = Component::Attack();
		attackComponent.attackDelay = 0.3f;
		attackComponent.interval = 1;
		Component::Damage damageComponent = Component::Damage();
		damageComponent.health = 50;

		Component::Position positionComponent = Component::Position();
		// Add the components
		manager->addComponent(eliteGuardId, textureComponent);
		manager->addComponent(eliteGuardId, transformComponent);
		manager->addComponent(eliteGuardId, attackComponent);
		manager->addComponent(eliteGuardId, damageComponent);
		manager->addComponent(eliteGuardId, positionComponent);
		return eliteGuardId;
	}
}