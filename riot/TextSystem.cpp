#include "TextSystem.h"

namespace System {

	void TextSystem::initialize(ECS::Manager* manager, Graphics* graphics) {
	}

	void TextSystem::update(float frameTime) {}

	void TextSystem::render() {
		graphics->spriteBegin();
		std::unordered_set<ECS::EntityIdType>* buttonPtrs = this->manager->getEntities<Entity::Button>();

		for (ECS::EntityIdType id : *buttonPtrs)
		{
			Component::Text textComponent = this->manager->getEntityComponent<Component::Text>(id);
			textComponent.font->print(textComponent.text, textComponent.fontx, textComponent.fonty);
		}
		graphics->spriteEnd();
	}

	void TextSystem::releaseAll() {
		std::unordered_set<ECS::EntityIdType>* buttonPtrs = this->manager->getEntities<Entity::Button>();

		for (ECS::EntityIdType id : *buttonPtrs)
		{
			Component::Text textComponent = this->manager->getEntityComponent<Component::Text>(id);

			textComponent.font->onLostDevice();
			return;
		}
	}

	void TextSystem::resetAll() {}




}