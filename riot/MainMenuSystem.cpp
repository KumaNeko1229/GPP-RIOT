#include "MainMenuSystem.h"

namespace System {

	void MainMenu::initialize(ECS::Manager* manager, Graphics* graphics, Input* input) {
		System::initialize(manager, graphics, input);

		textureComponent = Component::Texture();
		textureComponent.visible = true;
		textureComponent.viewableRect.left = 0;
		textureComponent.viewableRect.right = GAME_WIDTH;
		textureComponent.viewableRect.top = 0;
		textureComponent.viewableRect.bottom = GAME_HEIGHT;
		if (!textureComponent.loadTexture(graphics, MENU_IMAGE))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading background texture"));
		}

		textComponent = Component::Text();
		textComponent.font = new TextDX();
		textComponent.font->setFontColor(graphicsNS::WHITE);
		if (textComponent.font->initialize(graphics, 160, false, false, "Roboto") == false)
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing DirectX font"));
	}

	void MainMenu::render() {
		this->graphics->spriteBegin();

		LP_SPRITE sprite = this->graphics->getSprite();

		D3DXVECTOR2 translate = D3DXVECTOR2(
			0,
			0
		);

		D3DXMATRIX matrix;
		D3DXMatrixTransformation2D(
			&matrix,                   // the matrix
			NULL,                      // keep origin at top left when scaling
			0.0f,					   // no scaling rotation
			NULL,					   // scale amount
			NULL,						// rotation center
			NULL,						// rotation angle
			&translate);               // X,Y location

		sprite->SetTransform(&matrix);

		sprite->Draw(textureComponent.texture,
			&textureComponent.viewableRect,
			NULL,
			NULL,
			textureComponent.filter);

		textComponent.font->print("RIOT", (GAME_WIDTH / 3) + 50, GAME_HEIGHT / 4);

		float buttonx = GAME_WIDTH / 2;
		float startbuttony = GAME_HEIGHT / 2 + (GAME_HEIGHT / 2) / 4;
		float creditsbuttony = GAME_HEIGHT / 2 + ((GAME_HEIGHT / 2) / 4) * 2;
		float quitbuttony = GAME_HEIGHT / 2 + ((GAME_HEIGHT / 2) / 4) * 3;

		this->graphics->spriteEnd();
	}

	void MainMenu::update(float frametime) 
	{
		Entity::createButtonEntity(this->manager, this->graphics, "Start", GAME_WIDTH / 2, GAME_HEIGHT / 2 + (GAME_HEIGHT / 2) / 4,20);
		Entity::createButtonEntity(this->manager, this->graphics, "Credits", GAME_WIDTH / 2, GAME_HEIGHT / 2 + ((GAME_HEIGHT / 2) / 4) * 2,20);
		Entity::createButtonEntity(this->manager, this->graphics, "Quit", GAME_WIDTH / 2, GAME_HEIGHT / 2 + ((GAME_HEIGHT / 2) / 4) * 3,20);
	}

}

