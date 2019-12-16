#include "HUDSystem.h"

namespace System {

	void HUD::render() {
		Component::GameState& gameState = this->manager->getComponents<Component::GameState>()->at(0);
		if (gameState.displayState == Component::DisplayState::INGAME)
		{
			std::unordered_set<ECS::EntityIdType>* playerPtr = this->manager->getEntities<Entity::Player>();

			for (ECS::EntityIdType id : *playerPtr)
			{
				Component::Damage& damageComponent = this->manager->getEntityComponent<Component::Damage>(id);
				D3DCOLOR healthBarColor = D3DCOLOR_XRGB(255, 0, 0);
				D3DRECT healthbar = { 10, 10, 10 + (damageComponent.health / playerMaxHealth) * 150, 40 };
				LP_3DDEVICE device = graphics->get3Ddevice();
				device->Clear(1, &healthbar, D3DCLEAR_TARGET, healthBarColor, 0, 0);
			}
		}
	}

	void HUD::releaseAll() {};

	void HUD::resetAll() {};

	void HUD::update(float frameTime) {	};

}