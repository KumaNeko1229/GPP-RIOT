#include "GachaEntity.h"

namespace Entity {

	ECS::EntityIdType createGachaEntity(ECS::Manager* manager, Graphics* graphics) {
		ECS::EntityIdType GachaId = manager->createEntity<Gacha>();

		// Create the components
		// Create texture Component
		Component::Texture textureComponent = Component::Texture();
		if (!textureComponent.loadTexture(graphics, GACHA_IMAGE))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading gacha entity texture"));
		}
		textureComponent.visible = true;

		// Create transform component

		Component::Position positionComponent = Component::Position();
		positionComponent.x = 0;
		positionComponent.y = 0;

		Component::Transform transformComponent = Component::Transform();

		// Add the components
		manager->addComponent<Component::Texture>(GachaId, textureComponent);
		manager->addComponent<Component::Position>(GachaId, positionComponent);
		manager->addComponent<Component::Transform>(GachaId, transformComponent);
		return GachaId;
	}

}