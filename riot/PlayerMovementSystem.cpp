#include "PlayerMovementSystem.h"

namespace System {

	void PlayerMovementSystem::update(float frameTime)
	{
		std::unordered_set<ECS::EntityIdType>* playerPtrs = this->manager->getEntities<Entity::Player>();

		for (ECS::EntityIdType id : *playerPtrs)
		{
			Component::Physics& physicsComponent = this->manager->getEntityComponent<Component::Physics>(id);
			Component::Transform& transformComponent = this->manager->getEntityComponent<Component::Transform>(id);

			// reset the velocity of the object
			physicsComponent.velocityX = 0.0f;
			physicsComponent.velocityY = 0.0f;

			// check for WASD to add a velocity to the component
			if (input->isKeyDown(UP_KEY))
			{
				physicsComponent.velocityY = -120.0f;
				transformComponent.angle = UP_ANGLE;
			}

			if (input->isKeyDown(DOWN_KEY))
			{
				physicsComponent.velocityY = 120.0f;
				transformComponent.angle = DOWN_ANGLE;
			}

			if (input->isKeyDown(LEFT_KEY))
			{
				physicsComponent.velocityX = -120.0f;
				transformComponent.angle = LEFT_ANGLE;
			}

			if (input->isKeyDown(RIGHT_KEY))
			{
				physicsComponent.velocityX = 120.0f;
				transformComponent.angle = RIGHT_ANGLE;
			}
		}
	}
}