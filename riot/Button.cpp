#include "Button.h"

namespace Entity {

	ECS::EntityIdType createButtonEntity(ECS::Manager* manager, Graphics* graphics) {
		ECS::EntityIdType ButtonId = manager->createEntity<Button>();

		// Create the components
		// Create texture Component
		Component::Texture textureComponent = Component::Texture();
		//Should be button image
		if (!textureComponent.loadTexture(graphics, PLAYER_IMAGE))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading button entity texture"));
		}
		textureComponent.visible = true;

		// Create transform component
		Component::Transform transformComponent = Component::Transform();
		Component::Clickable clickableComponent = Component::Clickable();
		Component::Text textComponent = Component::Text();

		// Add the components
		manager->addComponent(ButtonId, textureComponent);
		manager->addComponent(ButtonId, transformComponent);
		manager->addComponent(ButtonId, clickableComponent);
		manager->addComponent(ButtonId, textComponent);

		return ButtonId;
	}

}