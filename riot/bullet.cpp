#include "bullet.h"

namespace Entity {

	ECS::EntityIdType createBulletEntity(ECS::Manager* manager, Graphics* graphics, int x, int y, float angle)
	{
		ECS::EntityIdType bulletId = manager->createEntity<Bullet>();

		// Create the components
		// Create the collidable component
		Component::Collidable collidableComponent = Component::Collidable();

		// create the physics component
		Component::Physics physicsComponent = Component::Physics();
		if (angle == UP_ANGLE)
		{
			physicsComponent.velocityY = -500.0f;
		}
		if (angle == DOWN_ANGLE)
		{
			physicsComponent.velocityY = 500.0f;
		}
		if (angle == LEFT_ANGLE)
		{
			physicsComponent.velocityX = -500.0f;
		}
		if (angle == RIGHT_ANGLE)
		{
			physicsComponent.velocityX = 500.0f;
		}

		// create the transform component
		Component::Transform transformComponent = Component::Transform();
		transformComponent.angle = angle;
		transformComponent.scale = SCALE_FACTOR * 2;

		// create the texture component
		Component::Texture textureComponent = Component::Texture();
		if (!textureComponent.loadTexture(graphics, BULLET_IMAGE))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading bullet entity texture"));
		}
		textureComponent.visible = true;

		// create the position component
		Component::Position positionComponent = Component::Position();
		positionComponent.x = x;
		positionComponent.y = y - (textureComponent.viewableRect.bottom - textureComponent.viewableRect.top);

		manager->addComponent<Component::Position>(bulletId, positionComponent);
		manager->addComponent<Component::Collidable>(bulletId, collidableComponent);
		manager->addComponent<Component::Physics>(bulletId, physicsComponent);
		manager->addComponent<Component::Transform>(bulletId, transformComponent);
		manager->addComponent<Component::Texture>(bulletId, textureComponent);

		return bulletId;
	}
}