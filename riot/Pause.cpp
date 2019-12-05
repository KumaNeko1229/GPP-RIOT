#include "Pause.h"

namespace Entity {

	ECS::EntityIdType createPauseEntity(ECS::Manager* manager, Graphics* graphics, float pausex, float pausey) {
		ECS::EntityIdType PauseId = manager->createEntity<Pause>();

		Component::Texture textureComponent = Component::Texture();
		if (!textureComponent.loadTexture(graphics, PAUSE_IMAGE))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading pause entity texture"));
		}
		textureComponent.visible = true;

		Component::Clickable clickableComponent = Component::Clickable();
		Component::Position positionComponent = Component::Position();
		Component::Text textComponent = Component::Text();
		textComponent.text = "Pause";
	
		positionComponent.x = pausex;
		positionComponent.y = pausey;
		// Add the components
		manager->addComponent(PauseId, textureComponent);
		manager->addComponent(PauseId, clickableComponent);
		manager->addComponent(PauseId, textComponent);

		return PauseId;
	}

}