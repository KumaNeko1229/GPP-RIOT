#include "Player.h"

namespace Entity {

ECS::EntityIdType createPlayerEntity(ECS::Manager* manager, Graphics* graphics) {
	ECS::EntityIdType playerId = manager->createEntity<Player>();

	// Create the components
	// Create texture Component
	Component::Texture textureComponent = Component::Texture();
	if (!textureComponent.loadTexture(graphics, PLAYER_IMAGE))
	{
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading player entity texture"));
	}
	textureComponent.visible = true;

	// Create transform component
	Component::Transform transformComponent = Component::Transform();
	transformComponent.angle = PI / 2;

	// Create animatable component
	Component::Animatable animatableComponent = Component::Animatable();
	animatableComponent.columns = 2;
	animatableComponent.rows = 4;
	animatableComponent.startFrame = 7;
	animatableComponent.endFrame = 7;
	animatableComponent.currentFrame = 7;
	animatableComponent.frameDelay = 0.2f;
	animatableComponent.frameTimeLeft = 1.0f;

	// Create position component
	Component::Position positionComponent = Component::Position();

	// Create the physics component
	Component::Physics physicsComponent = Component::Physics();

	// Create the attack component
	Component::Attack attackComponent = Component::Attack();

	// Add the components
	manager->addComponent<Component::Texture>(playerId, textureComponent);
	manager->addComponent<Component::Transform>(playerId, transformComponent);
	manager->addComponent<Component::Animatable>(playerId, animatableComponent);
	manager->addComponent<Component::Position>(playerId, positionComponent);
	manager->addComponent<Component::Physics>(playerId, physicsComponent);
	manager->addComponent<Component::Attack>(playerId, attackComponent);

	return playerId;
}

}