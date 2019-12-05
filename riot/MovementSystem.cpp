#include "MovementSystem.h"

namespace System {

	void Movement::update(float frameTime)
	{
		std::vector<Component::Physics>* componentsPtr = this->manager->getComponents<Component::Physics>();

		for (Component::Physics& physicsComponent : *componentsPtr)
		{
			Component::Position& positionComponent = manager->getEntityComponent<Component::Position>(physicsComponent.entityId);

			positionComponent.x += physicsComponent.velocityX * frameTime * SCALE_FACTOR;
			positionComponent.y += physicsComponent.velocityY * frameTime * SCALE_FACTOR;

			if (manager->getEntity(physicsComponent.entityId)->isSameType<Entity::TearGas>())
			{
				manager->getEntityComponent<Component::Damage>(physicsComponent.entityId).projectileDistanceLeft -= sqrt(
					pow((physicsComponent.velocityX * frameTime * SCALE_FACTOR), 2) + pow((physicsComponent.velocityY * frameTime * SCALE_FACTOR), 2)
				);
			}
		}
	}

}