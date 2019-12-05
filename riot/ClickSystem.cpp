#include "ClickSystem.h"

namespace System {
	void ClickSystem::update() {

		std::unordered_set<ECS::EntityIdType>* buttonPtrs = this->manager->getEntities<Entity::Button>();

		for (ECS::EntityIdType id : *buttonPtrs)
		{
			Component::Clickable& clickComponent = this->manager->getEntityComponent<Component::Clickable>(id);
			Component::Texture& textureComponent = this->manager->getEntityComponent<Component::Texture>(id);
			Component::Text& textComponent = this->manager->getEntityComponent<Component::Text>(id);
			if (input->getMouseLButton()) {
				if (clickComponent.click == false) {
					if (input->getMouseX() >= (int)textureComponent.viewableRect.left && input->getMouseX() <= (int)textureComponent.viewableRect.right 
						&& input->getMouseY() >= (int)textureComponent.viewableRect.top && input->getMouseY() <= (int)textureComponent.viewableRect.bottom) {
						clickComponent.click = true;
						if (textComponent.text == "Start") {
							//insert systems calling
						}
						if (textComponent.text == "Credits") {
							//insert systems calling

						}
						if (textComponent.text == "Quit") {
							//insert systems calling

						}
						if (textComponent.text == "Resume") {
							//insert systems calling

						}
						if (textComponent.text == "Back to Menu") {
							//insert systems calling

						}
						if (textComponent.text == "Spin") {
							int number = rand() % 100;
							std::unordered_set<ECS::EntityIdType>* playerPtrs = this->manager->getEntities<Entity::Player>();
							for (ECS::EntityIdType pid : *playerPtrs)
							{
								Component::Damage& damageComponent = this->manager->getEntityComponent<Component::Damage>(pid);
								if (number <= 0 && number <= 33) {
									damageComponent.health = 1;
									//insert system calling
								}
								else if (number <= 34 && number <= 66) {
									damageComponent.health = 10;
									//insert system calling
								}
								else {
									damageComponent.health = 20;
									//insert system calling
								}
							}
						}
					}
				}
			}
			input->setMouseLButton(FALSE);
		}

		std::unordered_set<ECS::EntityIdType>* pausePtrs = this->manager->getEntities<Entity::Pause>();
		for (ECS::EntityIdType id : *buttonPtrs)
		{
			Component::Clickable& clickComponent = this->manager->getEntityComponent<Component::Clickable>(id);
			Component::Texture& textureComponent = this->manager->getEntityComponent<Component::Texture>(id);
			if (input->getMouseLButton()) {
				if (clickComponent.click == false) {
					if (input->getMouseX() >= (int)textureComponent.viewableRect.left && input->getMouseX() <= (int)textureComponent.viewableRect.right
						&& input->getMouseY() >= (int)textureComponent.viewableRect.top && input->getMouseY() <= (int)textureComponent.viewableRect.bottom) {
						clickComponent.click = true;
						//call Pause system
					}
				}
			}
			input->setMouseLButton(FALSE);
		}

	}
}