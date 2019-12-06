#include "ReaperSystem.h"

namespace System {

	void Reaper::update(float frameTime)
	{
		// check if the tear gas entity should still be alive
		std::vector<Component::Life>* componentPtrs = this->manager->getComponents<Component::Life>();

		for (Component::Life& lifeComponent : *componentPtrs)
		{
			lifeComponent.timeToLive -= frameTime;
			if (lifeComponent.timeToLive <= 0)
			{
				this->manager->removeEntity<Entity::TearGas>(lifeComponent.entityId);
			}
		}

		// add the life component to the tear gas entity if it has reached the maximum range
		std::unordered_set<ECS::EntityIdType>* gasPtrs = this->manager->getEntities<Entity::TearGas>();

		for (ECS::EntityIdType id : *gasPtrs)
		{
			Component::Damage damageComponent = manager->getEntityComponent<Component::Damage>(id);

			// check that the life component has not been added before
			if (damageComponent.projectileDistanceLeft <= 0 && damageComponent.reductionCounter != 1)
			{
				// stop the tear gas from moving since it has reached the maximum range
				manager->getEntityComponent<Component::Physics>(id).velocityX = 0;
				manager->getEntityComponent<Component::Physics>(id).velocityY = 0;

				Component::Life lifeComponent = Component::Life();
				lifeComponent.timeToLive = 4;

				manager->addComponent(id, lifeComponent);
				damageComponent.reductionCounter = 1; // counter to ensure it does not re-attach a new life component
			}
		}
	}

}