#include "HealthBar.h"

namespace Entity {

	ECS::EntityIdType createHealthBarEntity(ECS::Manager* manager, Graphics* graphics) {
		ECS::EntityIdType HealthBarId = manager->createEntity<HealthBar>();

		// Create the components
		// Create texture Component
		Component::Texture textureComponent = Component::Texture();
		textureComponent.visible = true;

		// Create transform component
		Component::Transform transformComponent = Component::Transform();

		// Add the components
		manager->addComponent(HealthBarId, textureComponent);
		manager->addComponent(HealthBarId, transformComponent);
		return HealthBarId;
	}

}