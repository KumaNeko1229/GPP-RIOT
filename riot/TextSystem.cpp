#include "TextSystem.h"

namespace System {

	void TextSystem::initialize(ECS::Manager* manager, Graphics* graphics) {
		std::vector<Component::Texture>* TexturePtr = this->manager->getComponents<Component::Texture>();
		for (Component::Texture textureComponent : *TexturePtr)
		{
			Component::Text textComponent = this->manager->getEntityComponent<Component::Text>(textureComponent.entityId);
			if (textComponent.font->initialize(graphics, 40, false, false, "Arial") == false)
				throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing DirectX font"));
		}
	}

	void TextSystem::update(float frameTime) {}

	void TextSystem::render() {
		graphics->beginScene();
		std::vector<Component::Texture>* TexturePtr = this->manager->getComponents<Component::Texture>();

		for (Component::Texture textureComponent : *TexturePtr)
		{
			// Ignore non-visible components
			if (!textureComponent.visible) {
				continue;
			}

			Component::Text textComponent = this->manager->getEntityComponent<Component::Text>(textureComponent.entityId);

			Component::Transform transformComponent =
				this->manager->getEntityComponent<Component::Transform>(textureComponent.entityId);

			Component::Position positionComponent =
				this->manager->getEntityComponent<Component::Position>(textureComponent.entityId);

			long viewableWidth = textureComponent.viewableRect.right - textureComponent.viewableRect.left;
			long viewableHeight = textureComponent.viewableRect.bottom - textureComponent.viewableRect.top;

			int spriteCenterX = (int) (viewableWidth / 2 * transformComponent.scale);
			int spriteCenterY = (int) (viewableHeight / 2 * transformComponent.scale);

			textComponent.font->print(textComponent.text, spriteCenterX, spriteCenterY);

		}

		graphics->endScene();

	}

	void TextSystem::releaseAll() {
		std::vector<Component::Texture>* componentsPtr =
			this->manager->getComponents<Component::Texture>();

		// Release textures
		for (Component::Texture textureComponent : *componentsPtr)
		{
			SAFE_RELEASE(textureComponent.texture);
		}
	}

	void TextSystem::resetAll() {}




}