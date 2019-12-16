#include "ClickSystem.h"

namespace System {

	void ClickSystem::update(float frameTime)
	{
		std::unordered_set<ECS::EntityIdType>* buttonPtrs = this->manager->getEntities<Entity::Button>();
		if (input->getMouseLButton()) {
			for (ECS::EntityIdType id : *buttonPtrs)
			{
				Component::Clickable& clickComponent = this->manager->getEntityComponent<Component::Clickable>(id);
				Component::Texture& textureComponent = this->manager->getEntityComponent<Component::Texture>(id);
				Component::Position& positionComponent = this->manager->getEntityComponent<Component::Position>(id);
				Component::Transform& transformComponent = this->manager->getEntityComponent<Component::Transform>(id);

				Component::Text& textComponent = this->manager->getEntityComponent<Component::Text>(id);
				if (clickComponent.click == false) {
					if ((input->getMouseX() > (float)positionComponent.x) && (input->getMouseX() < ((float)positionComponent.x + ((float)textureComponent.totalWidth * transformComponent.scale)))
						&& (input->getMouseY() > (float)positionComponent.y) && (input->getMouseY() < ((float)positionComponent.y + ((float)textureComponent.totalHeight * transformComponent.scale)))) {
						clickComponent.click = true;
						Component::GameState& gameState = this->manager->getComponents<Component::GameState>()->at(0);
						if (textComponent.text == "Start") {
							//insert systems calling
							this->manager->removeEntity<Entity::Button>(id);
							gameState.displayState = Component::DisplayState::INGAME;
							clickComponent.click = false;
						}
						else if (textComponent.text == "Quit") {
							//insert systems calling
							PostQuitMessage(0);
						}
						else if (textComponent.text == "Resume") {
							//insert systems calling
							gameState.displayState = Component::DisplayState::INGAME;
							clickComponent.click = false;
						}
						else if (textComponent.text == "Back to Menu") {
							//insert systems calling
							gameState.displayState = Component::DisplayState::MENU;
							clickComponent.click = false;
						}
						else {
							int number = rand() % 100;
							std::unordered_set<ECS::EntityIdType>* playerPtrs = this->manager->getEntities<Entity::Player>();
							for (ECS::EntityIdType pid : *playerPtrs)
							{
								Component::Damage& damageComponent = this->manager->getEntityComponent<Component::Damage>(pid);
								if (number <= 0 && number <= 33) {
									damageComponent.health = 1;
									gameState.displayState = Component::DisplayState::INGAME;
									clickComponent.click = false;
								}
								else if (number <= 34 && number <= 66) {
									damageComponent.health = 10;
									gameState.displayState = Component::DisplayState::INGAME;
									clickComponent.click = false;


								}
								else {
									damageComponent.health = 20;
									gameState.displayState = Component::DisplayState::INGAME;
									clickComponent.click = false;
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
			Component::GameState& gameState = this->manager->getComponents<Component::GameState>()->at(0);
			if (input->getMouseLButton()) {
				if (clickComponent.click == false) {
					if (input->getMouseX() >= (int)textureComponent.viewableRect.left && input->getMouseX() <= (int)textureComponent.viewableRect.right
						&& input->getMouseY() >= (int)textureComponent.viewableRect.top && input->getMouseY() <= (int)textureComponent.viewableRect.bottom) {
						clickComponent.click = true;
						//call Pause system
						gameState.displayState = Component::DisplayState::PAUSED;
						clickComponent.click = false;
					}
				}
			}
			input->setMouseLButton(FALSE);
		}

	}
}