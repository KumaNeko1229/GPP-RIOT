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

		// Create the physics component
		Component::Physics physicsComponent = Component::Physics();

		Component::Animatable animatableComponent = Component::Animatable();
		animatableComponent.columns = 9;
		animatableComponent.rows = 3;
		animatableComponent.currentFrame = 13;
		animatableComponent.startFrame = 13;
		animatableComponent.endFrame = 13;

		// Add the components
		manager->addComponent(guardId, physicsComponent);
		manager->addComponent(guardId, textureComponent);
		manager->addComponent(guardId, transformComponent);
		manager->addComponent(guardId, attackComponent);
		manager->addComponent(guardId, damageComponent);
		manager->addComponent(guardId, positionComponent);
		manager->addComponent(guardId, animatableComponent);

		return guardId;
	}
}