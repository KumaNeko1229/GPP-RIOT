#include "MetalBulletEntity.h"

namespace Entity {

	ECS::EntityIdType createMetalBulletEntity(ECS::Manager* manager, Graphics* graphics, float x, float y, float enemyAngle, float bulletAngle)
	{
		ECS::EntityIdType metalBulletId = manager->createEntity<MetalBullet>();

		// Create the components
		// create the collidable component
		Component::Collidable collidableComponent = Component::Collidable();
		collidableComponent.onEnter = [metalBulletId](ECS::Manager* manager, ECS::EntityIdType id) {
			if (manager->getEntity(id)->isSameType<Entity::Player>())
			{
				manager->getEntityComponent<Component::Damage>(id).health -= 4;
				manager->removeEntity<Entity::MetalBullet>(metalBulletId);
			}
		};

		// create the position component
		Component::Position positionComponent = Component::Position();

		// create the texture component
		Component::Texture textureComponent = Component::Texture();
		if (!textureComponent.loadTexture(graphics, METAL_BULLET_IMAGE))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading bullet entity texture"));
		}
		textureComponent.visible = true;

		// create the physics component, and set its path or velocity
		Component::Physics physicsComponent = Component::Physics();
		if (enemyAngle == UP_ANGLE)
		{
			// position and velocity
			positionComponent.x = x - (textureComponent.viewableRect.right - textureComponent.viewableRect.left) / 2;
			positionComponent.y = y;
			physicsComponent.velocityX = 500 * cos(bulletAngle);
			physicsComponent.velocityY = 500 * sin(bulletAngle);
		}
		if (enemyAngle == DOWN_ANGLE)
		{
			positionComponent.x = x - (textureComponent.viewableRect.right - textureComponent.viewableRect.left) / 2;
			positionComponent.y = y;
			physicsComponent.velocityX = 500 * cos(bulletAngle);
			physicsComponent.velocityY = 500 * sin(bulletAngle);
		}
		if (enemyAngle == LEFT_ANGLE)
		{
			positionComponent.x = x;
			positionComponent.y = y - (textureComponent.viewableRect.right - textureComponent.viewableRect.left) / 2;
			physicsComponent.velocityX = 500 * cos(bulletAngle);
			physicsComponent.velocityY = 500 * sin(bulletAngle);
		}
		if (enemyAngle == RIGHT_ANGLE)
		{
			positionComponent.x = x;
			positionComponent.y = y - (textureComponent.viewableRect.right - textureComponent.viewableRect.left) / 2;
			physicsComponent.velocityX = 500 * cos(bulletAngle);
			physicsComponent.velocityY = 500 * sin(bulletAngle);
		}

		// create the transform component
		Component::Transform transformComponent = Component::Transform();
		transformComponent.angle = bulletAngle + PI / 2;
		transformComponent.scale = SCALE_FACTOR * 2;

		manager->addComponent<Component::Position>(metalBulletId, positionComponent);
		manager->addComponent<Component::Collidable>(metalBulletId, collidableComponent);
		manager->addComponent<Component::Physics>(metalBulletId, physicsComponent);
		manager->addComponent<Component::Transform>(metalBulletId, transformComponent);
		manager->addComponent<Component::Texture>(metalBulletId, textureComponent);

		return metalBulletId;
	}
}