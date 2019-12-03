#include "PlayerMovementSystem.h"

namespace System {

	void PlayerMovementSystem::update(float frameTime)
	{
		std::vector<Component::Physics>* componentsPtr = this->manager->getComponents<Component::Physics>();

		for (Component::Physics& physicsComponent : *componentsPtr)
		{
			// reset the velocity of the object
			physicsComponent.velocityX = 0.0f;
			physicsComponent.velocityY = 0.0f;

			// check for WASD to add a velocity component
			if (input->isKeyDown(UP_KEY))
			{
				physicsComponent.velocityY = -5.0f;
			}

			if (input->isKeyDown(DOWN_KEY))
			{
				physicsComponent.velocityY = 5.0f;
			}

			if (input->isKeyDown(LEFT_KEY))
			{
				physicsComponent.velocityX = -5.0f;
			}

			if (input->isKeyDown(RIGHT_KEY))
			{
				physicsComponent.velocityX = 5.0f;
			}
		}
	}
}