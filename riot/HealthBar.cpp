#include "HealthBar.h"

namespace Entity {

	ECS::EntityIdType createHealthBarEntity(ECS::Manager* manager, Graphics* graphics) {
		ECS::EntityIdType HealthBarId = manager->createEntity<HealthBar>();

		// Create the components
		// Create texture Component
		Component::Texture textureComponent = Component::Texture();
		//Should be health bar image
		if (!textureComponent.loadTexture(graphics, PLAYER_IMAGE))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading health bar entity texture"));
		}
		textureComponent.visible = true;

		// Create transform component
		Component::Transform transformComponent = Component::Transform();

		// Add the components
		manager->addComponent(HealthBarId, textureComponent);
		manager->addComponent(HealthBarId, transformComponent);
		return HealthBarId;
	}

}