#include "BulletEntity.h"

namespace Entity {

	ECS::EntityIdType createBulletEntity(ECS::Manager* manager, Graphics* graphics, float x, float y, float playerAngle, float bulletAngle)
	{
		ECS::EntityIdType bulletId = manager->createEntity<Bullet>();

		// Create the components
		// create the damage component
		Component::Damage damageComponent = Component::Damage();
		damageComponent.damage = 5;

		// create the collidable component
		Component::Collidable collidableComponent = Component::Collidable();

		collidableComponent.collisionType = CollisionUtil::CollisionType::CIRCLE;
		collidableComponent.onEnter = [bulletId, damageComponent](ECS::Manager* manager, ECS::EntityIdType id) {
			manager->getEntityComponent<Component::Damage>(id).health -= damageComponent.damage;
			manager->removeEntity<Entity::Bullet>(bulletId);
		};

		// create the position component
		Component::Position positionComponent = Component::Position();

		// create the texture component
		Component::Texture textureComponent = Component::Texture();
		if (!textureComponent.loadTexture(graphics, BULLET_IMAGE))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading bullet entity texture"));
		}
		textureComponent.visible = true;

		// create the physics component, and set its path or velocity
		Component::Physics physicsComponent = Component::Physics();
		if (playerAngle == UP_ANGLE)
		{
			// position and velocity
			positionComponent.x = x - (textureComponent.viewableRect.right - textureComponent.viewableRect.left) / 2;
			positionComponent.y = y;
			physicsComponent.velocityX = 500 * cos(bulletAngle);
			physicsComponent.velocityY = 500 * sin(bulletAngle);
		}
		if (playerAngle == DOWN_ANGLE)
		{
			positionComponent.x = x - (textureComponent.viewableRect.right - textureComponent.viewableRect.left) / 2;
			positionComponent.y = y;
			physicsComponent.velocityX = 500 * cos(bulletAngle);
			physicsComponent.velocityY = 500 * sin(bulletAngle);
		}
		if (playerAngle == LEFT_ANGLE)
		{
			positionComponent.x = x;
			positionComponent.y = y - (textureComponent.viewableRect.right - textureComponent.viewableRect.left) / 2;
			physicsComponent.velocityX = 500 * cos(bulletAngle);
			physicsComponent.velocityY = 500 * sin(bulletAngle);
		}
		if (playerAngle == RIGHT_ANGLE)
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

		manager->addComponent<Component::Position>(bulletId, positionComponent);
		manager->addComponent<Component::Collidable>(bulletId, collidableComponent);
		manager->addComponent<Component::Physics>(bulletId, physicsComponent);
		manager->addComponent<Component::Transform>(bulletId, transformComponent);
		manager->addComponent<Component::Texture>(bulletId, textureComponent);

		return bulletId;
	}
}