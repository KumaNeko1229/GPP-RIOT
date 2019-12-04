#include "TearGas.h"

namespace Entity {

	ECS::EntityIdType createTearGasEntity(ECS::Manager* manager, Graphics* graphics)
	{
		ECS::EntityIdType tearGasID = manager->createEntity<Entity::TearGas>();

		// Create the components
		// create the physics component
		Component::Physics physicsComponent = Component::Physics();

		// create the position component 
		Component::Position positionComponent = Component::Position();

		// create the collidable component
		Component::Collidable collidableComponent = Component::Collidable();
		collidableComponent.onEnter = [tearGasID](ECS::Manager* manager, ECS::EntityIdType id) {
			// on collide with player start dealing initial damage
		};

		collidableComponent.onStay = [tearGasID](ECS::Manager* manager, ECS::EntityIdType id) {
			// mimmick the damage per second
		};

		// create the texture component
		Component::Texture textureComponent = Component::Texture();
		if (!textureComponent.loadTexture(graphics, TEAR_GAS_IMAGE))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading tear gas entity texture"));
		}
		textureComponent.visible = true;

		// create the transform component
		Component::Transform transformComponent = Component::Transform();

		// create the animatable component
		Component::Animatable animatableComponent = Component::Animatable();
		animatableComponent.rows = 2;
		animatableComponent.columns = 1;
		animatableComponent.currentFrame = 1;
		animatableComponent.startFrame = 1;
		animatableComponent.endFrame = 1;
		animatableComponent.frameDelay = 0.2f;
		animatableComponent.frameTimeLeft = 0.2f;

		manager->addComponent<Component::Physics>(tearGasID, physicsComponent);
		manager->addComponent<Component::Position>(tearGasID, positionComponent);
		manager->addComponent<Component::Texture>(tearGasID, textureComponent);
		manager->addComponent<Component::Transform>(tearGasID, transformComponent);
		manager->addComponent<Component::Animatable>(tearGasID, animatableComponent);
		return tearGasID;
	}

}