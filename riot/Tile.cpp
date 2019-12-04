#include "Tile.h"

namespace Entity {

	ECS::EntityIdType createTileEntity(ECS::Manager* manager, Graphics* graphics, int X, int Y) {
		ECS::EntityIdType tileId = manager->createEntity<Tile>();
		// Create the components
	// Create texture Component
		Component::Texture textureComponent = Component::Texture();

		if (!textureComponent.loadTexture(graphics, FLOOR_IMAGE))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading player entity texture"));
		}
		textureComponent.visible = true;

		// Create transform component
		Component::Transform transformComponent = Component::Transform();

		float posX = (float) (X * tileWidth);
		float posY = (float) (Y * tileHeight);

		// Create position component
		Component::Position positionComponent = Component::Position();
		positionComponent.x = posX;
		positionComponent.y = posY;

		// Add the components
		manager->addComponent<Component::Texture>(tileId, textureComponent);
		manager->addComponent<Component::Transform>(tileId, transformComponent);
		manager->addComponent<Component::Position>(tileId, positionComponent);

		return tileId;
	}

}