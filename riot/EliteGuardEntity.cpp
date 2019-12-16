#include "EliteGuardEntity.h"

namespace Entity {

	ECS::EntityIdType createEliteGuardEntity(ECS::Manager* manager, Graphics* graphics, int x, int y) {
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

		// Create the physics component
		Component::Physics physicsComponent = Component::Physics();

		Component::Position positionComponent = Component::Position();
		positionComponent.x = x * tileWidth;
		positionComponent.y = y * tileHeight;

		Component::Animatable animatableComponent = Component::Animatable();
		animatableComponent.columns = 9;
		animatableComponent.rows = 3;
		animatableComponent.currentFrame = 11;
		animatableComponent.startFrame = 11;
		animatableComponent.endFrame = 11;

		// Add the components
		manager->addComponent<Component::Texture>(eliteGuardId, textureComponent);
		manager->addComponent<Component::Transform>(eliteGuardId, transformComponent);
		manager->addComponent<Component::Attack>(eliteGuardId, attackComponent);
		manager->addComponent<Component::Physics>(eliteGuardId, physicsComponent);
		manager->addComponent<Component::Damage>(eliteGuardId, damageComponent);
		manager->addComponent<Component::Position>(eliteGuardId, positionComponent);
		manager->addComponent<Component::Animatable>(eliteGuardId, animatableComponent);

		return eliteGuardId;
	}
}