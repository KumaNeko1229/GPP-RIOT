#include "PlayerAttackSystem.h"

namespace System {

	// check for the timer, and create the bullets here
	void PlayerAttackSystem::update(float frameTime)
	{
		std::vector<Component::Attack>* componentPtrs = this->manager->getComponents<Component::Attack>();

		for (Component::Attack attackComponent : *componentPtrs)
		{
			attackComponent.cooldownTime -= frameTime;
			if (attackComponent.cooldownTime >= 0)
			{
				if (input->getMouseLButton())
				{
					// get the position of the player entity
					std::unordered_set<ECS::EntityIdType>* playerPtrs = this->manager->getEntities<Entity::Player>();
					for (ECS::EntityIdType id : *playerPtrs)
					{
						// get the position of the player
						Component::Position positionComponent = this->manager->getEntityComponent<Component::Position>(id);
						// create the bullet here
						Entity::createBulletEntity(this->manager, this->graphics, positionComponent.x, positionComponent.y);
						attackComponent.cooldownTime = attackComponent.interval;
						input->setMouseLButton(FALSE);
					}
				}
			}
		}
	}
}
