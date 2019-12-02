#include "PlayerMovementSystem.h"

namespace System {

	void initialize(ECS::Manager* manager) {}

	void PlayerMovementSystem::update(float frameTime) 
	{
		std::vector<Component::Physics>* componentsPtr = this->manager->getComponents<Component::Physics>();

		for (Component::Physics physicsComponent : *componentsPtr)
		{
			// get the position component of the objects
			Component::Position positionComponent = manager->getEntityComponent<Component::Position>(physicsComponent.entityId);
			// update the velocity of the component'
			physicsComponent.velocity += physicsComponent.acceleration * frameTime;

			if (input->isKeyDown(UP_KEY))
			{
				positionComponent.y -= physicsComponent.velocity * frameTime;
			}

			if (input->isKeyDown(DOWN_KEY))
			{
				positionComponent.y += physicsComponent.velocity * frameTime;
			}

			if (input->isKeyDown(LEFT_KEY))
			{
				positionComponent.x -= physicsComponent.velocity * frameTime;
			}

			if (input->isKeyDown(RIGHT_KEY))
			{
				positionComponent.x += physicsComponent.velocity * frameTime;
			}
		}
	}
}