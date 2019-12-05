#include "GachaSystem.h"

namespace System {

	void System::Gacha::update()
	{
		std::unordered_set<ECS::EntityIdType>* playerPtrs = this->manager->getEntities<Entity::Player>();

		for (ECS::EntityIdType id : *playerPtrs)
		{
			if (manager->getEntityComponent<Component::Damage>(id).health <= 0 && manager->getEntityComponent<Component::Damage>(id).revive == false)
			{
				// display the gacha menu here, then continue the game when its done
				D3DCOLOR boxColor = D3DCOLOR_XRGB(0, 0, 0);
				D3DRECT box = { 0, GAME_HEIGHT/4, GAME_WIDTH, GAME_HEIGHT / 3 };
				LP_3DDEVICE device = graphics->get3Ddevice();
				device->Clear(3, &box, D3DCLEAR_TARGET, boxColor, 0, 0);

				Entity::createButtonEntity(this->manager, this->graphics, "Spin", GAME_WIDTH / 2, GAME_HEIGHT / 3);

				manager->getEntityComponent<Component::Damage>(id).revive = true;
			}
		}
	}

}
