#include "HUDSystem.h"

namespace System {

	void HUDSystem::update(float frameTime) {};

	void HUDSystem::render() {
		graphics->beginScene();
		std::vector<Component::Texture>* TexturePtr = this->manager->getComponents<Component::Texture>();

		for (Component::Texture textureComponent : *TexturePtr)
		{
			// Ignore non-visible components
			if (!textureComponent.visible) {
				continue;
			}

			Component::Transform transformComponent =
				this->manager->getEntityComponent<Component::Transform>(textureComponent.entityId);

			Component::Position positionComponent =
				this->manager->getEntityComponent<Component::Position>(textureComponent.entityId);

		}

		graphics->endScene();

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
}