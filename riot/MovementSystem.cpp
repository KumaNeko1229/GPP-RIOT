#include "MovementSystem.h"

namespace System {

	void Movement::update(float frameTime)
	{
		Component::GameState& gameState = this->manager->getComponents<Component::GameState>()->at(0);
		if (gameState.displayState == Component::DisplayState::INGAME)
		{
			std::vector<Component::Physics>* componentsPtr = this->manager->getComponents<Component::Physics>();

			for (Component::Physics& physicsComponent : *componentsPtr)
			{
				Component::Position& positionComponent = manager->getEntityComponent<Component::Position>(physicsComponent.entityId);

				float xOffset = physicsComponent.velocityX * frameTime * SCALE_FACTOR;
				float yOffset = physicsComponent.velocityY * frameTime * SCALE_FACTOR;

				if (xOffset == 0 && yOffset == 0)
				{
					continue;
				}

				positionComponent.x += xOffset;
				positionComponent.y += yOffset;

				// Update the collision component if the entity has one
				if (this->manager->entityHasComponent<Component::Collidable>(physicsComponent.entityId))
				{
					Component::Collidable& collidableComponent =
						this->manager->getEntityComponent<Component::Collidable>(physicsComponent.entityId);

					for (D3DXVECTOR2& cornerVector : collidableComponent.corners)
					{
						cornerVector.x += xOffset;
						cornerVector.y += yOffset;
					}
				}

				if (manager->getEntity(physicsComponent.entityId)->isSameType<Entity::TearGas>())
				{
					manager->getEntityComponent<Component::Damage>(physicsComponent.entityId).projectileDistanceLeft -= (pow((physicsComponent.velocityX * frameTime * SCALE_FACTOR), 2) + pow((physicsComponent.velocityY * frameTime * SCALE_FACTOR), 2));
				}

			}
		}
	}

}