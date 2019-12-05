#include "GachaSystem.h"

namespace System {

	void System::GachaSystem::update()
	{
		std::unordered_set<ECS::EntityIdType>* playerPtrs = this->manager->getEntities<Entity::Player>();

		for (ECS::EntityIdType id : *playerPtrs)
		{
			if (manager->getEntityComponent<Component::Damage>(id).health <= 0)
			{
				// display the gacha menu here, then continue the game when its done
			}
		}
	}

}
