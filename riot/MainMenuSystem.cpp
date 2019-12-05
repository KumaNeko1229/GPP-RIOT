#include "MainMenuSystem.h"

namespace System {

	void MainMenu::render(ECS::Manager* manager) {
		this->graphics->spriteBegin();

		LP_SPRITE sprite = this->graphics->getSprite();

		// Get all texture components
		std::vector<Component::Texture>* texturePtr =
			this->manager->getComponents<Component::Texture>();

		for (Component::Texture textureComponent : *texturePtr)
		{
			if (!textureComponent.loadTexture(graphics, MENU_IMAGE))
			{
				throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading background texture"));
			}

			sprite->Draw(textureComponent.texture,
				&textureComponent.viewableRect,
				NULL,
				NULL,
				textureComponent.filter);
		}

		Entity::createButtonEntity(this->manager, this->graphics, "Start", GAME_WIDTH / 2, GAME_HEIGHT / 4);
		Entity::createButtonEntity(this->manager, this->graphics, "Credits", GAME_WIDTH / 2, GAME_HEIGHT / 3);
		Entity::createButtonEntity(this->manager, this->graphics, "Quit", GAME_WIDTH / 2, GAME_HEIGHT / 2);

		this->graphics->spriteEnd();
	}

}