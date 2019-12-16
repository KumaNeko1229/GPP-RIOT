#include "EliteSoldierEntity.h"

namespace Entity {

	ECS::EntityIdType createEliteSoldierEntity(ECS::Manager* manager, Graphics* graphics, int x, int y) {
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

		Component::Attack attackComponent = Component::Attack();
		attackComponent.attackDelay = 0.2f;
		attackComponent.interval = 1;
		Component::Damage damageComponent = Component::Damage();
		damageComponent.health = 60;

		Component::Position positionComponent = Component::Position();
		positionComponent.x = x * tileWidth;
		positionComponent.y = y * tileHeight;

		// Create the physics component
		Component::Physics physicsComponent = Component::Physics();

		Component::Animatable animatableComponent = Component::Animatable();
		animatableComponent.columns = 9;
		animatableComponent.rows = 3;
		animatableComponent.currentFrame = 8;
		animatableComponent.startFrame = 8;
		animatableComponent.endFrame = 8;

		// Add the components
		manager->addComponent<Component::Texture>(eliteSoldierId, textureComponent);
		manager->addComponent<Component::Physics>(eliteSoldierId, physicsComponent);
		manager->addComponent<Component::Transform>(eliteSoldierId, transformComponent);
		manager->addComponent<Component::Attack>(eliteSoldierId, attackComponent);
		manager->addComponent<Component::Damage>(eliteSoldierId, damageComponent);
		manager->addComponent<Component::Position>(eliteSoldierId, positionComponent);
		manager->addComponent<Component::Animatable>(eliteSoldierId, animatableComponent);

		return eliteSoldierId;
	}

}