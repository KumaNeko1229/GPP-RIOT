#include "ClickSystem.h"

namespace System {
	void ClickSystem::update(float frametime) {

		std::unordered_set<ECS::EntityIdType>* buttonPtrs = this->manager->getEntities<Entity::Button>();

		for (ECS::EntityIdType id : *buttonPtrs)
		{
			Component::Clickable& clickComponent = this->manager->getEntityComponent<Component::Clickable>(id);
			Component::Texture& textureComponent = this->manager->getEntityComponent<Component::Texture>(id);
			if (input->getMouseLButton()) {
				if (clickComponent.click == false) {
					if (input->getMouseX() >= (int)textureComponent.viewableRect.left && input->getMouseX() <= (int)textureComponent.viewableRect.right 
						&& input->getMouseY() >= (int)textureComponent.viewableRect.top && input->getMouseY() <= (int)textureComponent.viewableRect.bottom) {
						clickComponent.click = true;
					}
				}
			}
			input->setMouseLButton(FALSE);
		}
	}
}