#include "HalfwallEntity.h"

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
		std::vector<D3DXVECTOR2> corners = {
			{(float)X * tileWidth, (float)Y * tileHeight},
			{(float)(X + 1) * tileWidth, (float)Y * tileHeight},
			{(float)X * tileHeight, (float)(Y + 1) * tileHeight},
			{(float)(X + 1) * tileWidth, (float)(Y + 1) * tileHeight}
		};
		collidableComponent.collisionType = CollisionUtil::CollisionType::CIRCLE;
		collidableComponent.corners = corners;
		collidableComponent.onEnter = [halfwallId](ECS::Manager* manager, ECS::EntityIdType id) {
			if (manager->getEntity(id)->isSameType<Entity::Player>()
				|| manager->getEntity(id)->isSameType<Entity::Blocker>()
				|| manager->getEntity(id)->isSameType<Entity::Guard>()
				|| manager->getEntity(id)->isSameType<Entity::EliteGuard>()
				|| manager->getEntity(id)->isSameType<Entity::EliteSoldier>())
			{

				Component::Collidable& entityCorner = manager->getEntityComponent<Component::Collidable>(id);
				Component::Position wallPos = manager->getEntityComponent<Component::Position>(halfwallId);
				Component::Position &entityPos = manager->getEntityComponent<Component::Position>(id);
				float wallCenX = wallPos.x + (tileWidth / 2);
				float wallCenY = wallPos.y + (tileHeight / 2);
				float entityCenX = entityPos.x + (tileWidth / 2);
				float entityCenY = entityPos.y + (tileHeight / 2);
				if (wallCenX < entityPos.x < (wallPos.x + tileWidth))
				{
					entityPos.x += wallPos.x + tileWidth - entityPos.x;
				}
				else if (wallPos.x < (entityPos.x + tileWidth) < wallCenX)
				{
					entityPos.x -= entityPos.x - wallPos.x;
				}
				if (wallCenY < entityPos.y < wallPos.y + tileHeight)
				{
					entityPos.y += wallPos.y + tileHeight - entityPos.y;
				}
				else if (wallPos.y < entityPos.y < wallCenY)
				{
					entityPos.y -= entityPos.y - wallPos.y;
				}

				std::vector<D3DXVECTOR2> corners = {
					{(float)entityPos.x, (float)entityPos.y},
					{(float)entityPos.x + tileWidth, (float)entityPos.y},
					{(float)entityPos.x, (float)entityPos.y + tileHeight},
					{(float)entityPos.x + tileWidth, (float)entityPos.y + tileHeight}
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
		manager->addComponent<Component::Collidable>(halfwallId, collidableComponent);
		manager->addComponent<Component::Texture>(halfwallId, textureComponent);
		manager->addComponent<Component::Transform>(halfwallId, transformComponent);
		manager->addComponent<Component::Position>(halfwallId, positionComponent);

		return halfwallId;
	}

}