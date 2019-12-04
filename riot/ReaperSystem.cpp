#include "ReaperSystem.h"

namespace System {
	
	void ReaperSystem::update(float frameTime)
	{
		std::vector<Component::Life>* componentPtrs = this->manager->getComponents<Component::Life>();
		
		for (Component::Life& lifeComponent : *componentPtrs)
		{
			lifeComponent.timeToLive -= frameTime;
			if (lifeComponent.timeToLive <= 0)
			{
				this->manager->removeEntity<Entity::TearGas>(lifeComponent.entityId);
			}
		}
	}

}