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

		// create the life component
		Component::Life lifeComponent = Component::Life();

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
		//animatableComponent.rows = 
		//animatableComponent.columns = 

		manager->addComponent<Component::Physics>(tearGasID, physicsComponent);
		manager->addComponent<Component::Position>(tearGasID, positionComponent);
		manager->addComponent<Component::Life>(tearGasID, lifeComponent);
		manager->addComponent<Component::Texture>(tearGasID, textureComponent);
		manager->addComponent<Component::Transform>(tearGasID, transformComponent);
		manager->addComponent<Component::Animatable>(tearGasID, animatableComponent);
		return tearGasID;
	}

}