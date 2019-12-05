#include "Button.h"

namespace Entity {

	ECS::EntityIdType createButtonEntity(ECS::Manager* manager, Graphics* graphics, std::string buttonName, float buttonx, float buttony) {
		ECS::EntityIdType ButtonId = manager->createEntity<Button>();

		// Create the components
		// Create texture Component
		Component::Texture textureComponent = Component::Texture();
		// Create transform component
		D3DCOLOR boxColor = D3DCOLOR_XRGB(255, 255, 255);
		D3DRECT box = { buttonx-25, buttony-15, buttonx + 25, buttony+15 };
		LP_3DDEVICE device = graphics->get3Ddevice();
		device->Clear(1, &box, D3DCLEAR_TARGET, boxColor, 0, 0);

		textureComponent.viewableRect.left = buttonx-25;
		textureComponent.viewableRect.right = buttonx+25;
		textureComponent.viewableRect.top = buttony-15;
		textureComponent.viewableRect.bottom = buttony+15;

		Component::Clickable clickableComponent = Component::Clickable();
		Component::Position positionComponent = Component::Position();
		Component::Text textComponent = Component::Text();
		textComponent.text = buttonName;
		if (textComponent.font->initialize(graphics, 40, false, false, "Arial") == false)
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing DirectX font"));
		textComponent.font->print(textComponent.text, buttonx, buttony);
		positionComponent.x = buttonx;
		positionComponent.y = buttony;
		// Add the components
		manager->addComponent(ButtonId, textureComponent);
		manager->addComponent(ButtonId, clickableComponent);
		manager->addComponent(ButtonId, textComponent);

		return ButtonId;
	}

}