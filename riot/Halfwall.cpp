#include "Halfwall.h"

namespace Entity {

	ECS::EntityIdType createHalfwallEntity(ECS::Manager* manager, Graphics* graphics, int X, int Y) {
		ECS::EntityIdType halfwallId = manager->createEntity<Halfwall>();
		// Create the components
	// Create texture Component
		Component::Texture textureComponent = Component::Texture();

		if (!textureComponent.loadTexture(graphics, HALFWALL_IMAGE))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading player entity texture"));
		}
		textureComponent.visible = true;
		Component::Collidable collidableComponent = Component::Collidable();
		manager->addComponent<Component::Collidable>(halfwallId, collidableComponent);

		// Create transform component
		Component::Transform transformComponent = Component::Transform();

		float posX = (float)(X * tileWidth);
		float posY = (float)(Y * tileHeight);

		// Create position component
		Component::Position positionComponent = Component::Position();
		positionComponent.x = posX;
		positionComponent.y = posY;

		// Add the components
		manager->addComponent<Component::Texture>(halfwallId, textureComponent);
		manager->addComponent<Component::Transform>(halfwallId, transformComponent);
		manager->addComponent<Component::Position>(halfwallId, positionComponent);

		return halfwallId;
	}

}