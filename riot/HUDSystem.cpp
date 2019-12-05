#include "HUDSystem.h"

namespace System {
	
	void HUDSystem::render() {
		//graphics->beginScene();
		//std::vector<Component::Texture>* TexturePtr = this->manager->getComponents<Component::Texture>();
		//
		//for (Component::Texture textureComponent : *TexturePtr)
		//{
		//	// Ignore non-visible components
		//	if (!textureComponent.visible) {
		//		continue;
		//	}

		//	Component::Transform transformComponent =
		//		this->manager->getEntityComponent<Component::Transform>(textureComponent.entityId);

		//	Component::Position positionComponent =
		//		this->manager->getEntityComponent<Component::Position>(textureComponent.entityId);

		//}

		//graphics->endScene();

	}

	void HUDSystem::releaseAll() {
		std::vector<Component::Texture>* componentsPtr =
			this->manager->getComponents<Component::Texture>();

		// Release textures
		for (Component::Texture textureComponent : *componentsPtr)
		{
			SAFE_RELEASE(textureComponent.texture);
		}
	}

	void HUDSystem::resetAll() {};

	void HUDSystem::update(float frameTime) {
		std::unordered_set<ECS::EntityIdType>* playerPtr = this->manager->getEntities<Entity::Player>();

		for (ECS::EntityIdType id : *playerPtr)
		{
			Component::Damage& damageComponent = this->manager->getEntityComponent<Component::Damage>(id);
			float playerMaxHealth = 20.0;
			D3DCOLOR healthBarColor = D3DCOLOR_XRGB(255, 0, 0);
			D3DRECT healthbar = { 10, 10, 10 + (damageComponent.health / playerMaxHealth) * 100, 40 };
			LP_3DDEVICE device = graphics->get3Ddevice();
			device->Clear(1, &healthbar, D3DCLEAR_TARGET, healthBarColor, 0, 0);
		}
	
	};

}