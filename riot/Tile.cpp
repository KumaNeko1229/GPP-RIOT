#include "Tile.h"

namespace Entity {

	ECS::EntityIdType createTileEntity(ECS::Manager* manager, Graphics* graphics, int X, int Y, int TileType) {
		ECS::EntityIdType tileId = manager->createEntity<Tile>();
		// Create the components
	// Create texture Component
		Component::Texture textureComponent = Component::Texture();

		if (TileType == 0)
		{
			if (!textureComponent.loadTexture(graphics, FLOOR_IMAGE))
			{
				throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading player entity texture"));
			}
			textureComponent.visible = true;
		} else if (TileType == 1)
		{
			if (!textureComponent.loadTexture(graphics, WALL_IMAGE))
			{
				throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading player entity texture"));
			}
			textureComponent.visible = true;
			Component::Collidable collidableComponent = Component::Collidable();
			manager->addComponent<Component::Collidable>(tileId, collidableComponent);
		} else
		{
			if (!textureComponent.loadTexture(graphics, HALFWALL_IMAGE))
			{
				throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading player entity texture"));
			}
			textureComponent.visible = true;
			Component::Collidable collidableComponent = Component::Collidable();
			manager->addComponent<Component::Collidable>(tileId, collidableComponent);
		}

		// Create transform component
		Component::Transform transformComponent = Component::Transform();

		float posX = X * tileWidth;
		float posY = Y * tileHeight;

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