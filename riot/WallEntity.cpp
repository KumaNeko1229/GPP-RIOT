#include "WallEntity.h"

namespace Entity {

	ECS::EntityIdType createWallEntity(ECS::Manager* manager, Graphics* graphics, int X, int Y) {
		ECS::EntityIdType wallId = manager->createEntity<Wall>();
		// Create the components
		// Create texture Component
		Component::Texture textureComponent = Component::Texture();

		if (!textureComponent.loadTexture(graphics, WALL_IMAGE))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading player entity texture"));
		}
		textureComponent.visible = true;
		Component::Collidable collidableComponent = Component::Collidable();
		std::vector<D3DXVECTOR2> corners = {
			{(float)(X) * tileWidth, (float)(Y) * tileHeight},
			{(float)(X + 1) * tileWidth, (float)(Y) * tileHeight},
			{(float)(X) * tileWidth, (float)(Y + 1) * tileHeight},
			{(float)(X + 1) * tileWidth, (float)(Y + 1) * tileHeight}
		};
		collidableComponent.collisionType = CollisionUtil::CollisionType::AABB;
		collidableComponent.corners = corners;
		collidableComponent.onEnter = [wallId](ECS::Manager* manager, ECS::EntityIdType id) {
			if (manager->getEntity(id)->isSameType<Entity::Player>()
				|| manager->getEntity(id)->isSameType<Entity::Blocker>()
				|| manager->getEntity(id)->isSameType<Entity::Guard>()
				|| manager->getEntity(id)->isSameType<Entity::EliteGuard>()
				|| manager->getEntity(id)->isSameType<Entity::EliteSoldier>())
			{
				Component::Position wallPos = manager->getEntityComponent<Component::Position>(wallId);
				Component::Position &entityPos = manager->getEntityComponent<Component::Position>(id);
				Component::Collidable& entityCorner = manager->getEntityComponent<Component::Collidable>(id);
				float wallCenX = wallPos.x + (tileWidth / 2);
				float wallCenY = wallPos.y + (tileHeight / 2);
				float entityCenX = entityPos.x + (tileWidth / 2);
				float entityCenY = entityPos.y + (tileHeight / 2);
				
				if (wallCenX < entityCenX < (wallPos.x + tileWidth))
				{
					entityPos.x += wallPos.x + tileWidth - entityPos.x;
				}
				else if (wallPos.x < entityCenX < wallCenX)
				{
					entityPos.x -= (entityCenX - wallPos.x);
				}
				if (wallCenY < entityCenY < wallPos.y + tileHeight)
				{
					entityPos.y += wallPos.y + tileHeight - entityPos.y;
				}
				else if (wallPos.y < entityCenY < wallCenY)
				{
					entityPos.y -= entityCenY - wallPos.y;
				}

				std::vector<D3DXVECTOR2> corners = {
					{(float)entityPos.x + 4, (float)entityPos.y + 4},
					{(float)entityPos.x + 40, (float)entityPos.y + 4},
					{(float)entityPos.x + 4, (float)entityPos.y + 40},
					{(float)entityPos.x + 40, (float)entityPos.y + 40}
				};

				entityCorner.corners = corners;
			}
		};

		// Create transform component
		Component::Transform transformComponent = Component::Transform();

		float posX = (float)(X * tileWidth);
		float posY = (float)(Y * tileHeight);

		// Create position component
		Component::Position positionComponent = Component::Position();
		positionComponent.x = posX;
		positionComponent.y = posY;

		// Add the components
		manager->addComponent<Component::Collidable>(wallId, collidableComponent);
		manager->addComponent<Component::Texture>(wallId, textureComponent);
		manager->addComponent<Component::Transform>(wallId, transformComponent);
		manager->addComponent<Component::Position>(wallId, positionComponent);

		return wallId;
	}

}