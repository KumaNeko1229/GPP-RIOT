#include "GachaSystem.h"

namespace System {

	void System::Gacha::update()
	{
		std::unordered_set<ECS::EntityIdType>* playerPtrs = this->manager->getEntities<Entity::Player>();

		for (ECS::EntityIdType id : *playerPtrs)
		{
			if (manager->getEntityComponent<Component::Damage>(id).health <= 0 && manager->getEntityComponent<Component::Damage>(id).revive == false)
			{
				Entity::createGachaEntity(this->manager, this->graphics);
				Entity::createButtonEntity(this->manager, this->graphics, "Spin", GAME_WIDTH / 2, (GAME_HEIGHT / 4)*3, 20);
				manager->getEntityComponent<Component::Damage>(id).revive = true;
			}
		}
	}

}
