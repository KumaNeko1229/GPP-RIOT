#include "ButtonEntity.h"

namespace Entity {

	ECS::EntityIdType createButtonEntity(ECS::Manager* manager, Graphics* graphics, std::string buttonName, float buttonx, float buttony, float fontsize) {
		ECS::EntityIdType ButtonId = manager->createEntity<Button>();

		// Create the components
		// Create texture Component
		Component::Texture textureComponent = Component::Texture();
		if (!textureComponent.loadTexture(graphics, BUTTON_IMAGE))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading button entity texture"));
		}
		textureComponent.visible = true;

		// Create transform component

		Component::Position positionComponent = Component::Position();
		positionComponent.x = buttonx;
		positionComponent.y = buttony;

		Component::Transform transformComponent = Component::Transform();
		transformComponent.scale = 0.5;

		Component::Clickable clickableComponent = Component::Clickable();
		clickableComponent.click = false;

		Component::Text textComponent = Component::Text();
		textComponent.font = new TextDX();
		textComponent.text = buttonName;
		textComponent.fontsize = fontsize;
		textComponent.fontx = buttonx + 30;
		textComponent.fonty = buttony + 20;
		textComponent.font->setFontColor(graphicsNS::BLACK);
		if (textComponent.font->initialize(graphics, textComponent.fontsize, false, false, "Arial") == false)
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing DirectX font"));

		// Add the components
		manager->addComponent(ButtonId, textureComponent);
		manager->addComponent(ButtonId, clickableComponent);
		manager->addComponent(ButtonId, textComponent);
		manager->addComponent(ButtonId, positionComponent);
		manager->addComponent(ButtonId, textureComponent);
		manager->addComponent(ButtonId, transformComponent);
		return ButtonId;
	}

}