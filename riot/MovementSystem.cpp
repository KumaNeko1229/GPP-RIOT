#include "MovementSystem.h"

namespace System {

	void MovementSystem::update(float frameTime)
	{
		std::vector<Component::Physics>* componentsPtr = this->manager->getComponents<Component::Physics>();

		for (Component::Physics& physicsComponent : *componentsPtr)
		{
			Component::Position& positionComponent = manager->getEntityComponent<Component::Position>(physicsComponent.entityId);
			positionComponent.x += physicsComponent.velocityX * frameTime * SCALE_FACTOR;
			positionComponent.y += physicsComponent.velocityY * frameTime * SCALE_FACTOR;
		}
	}

}