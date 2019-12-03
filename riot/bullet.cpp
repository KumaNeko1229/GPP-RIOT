#include "bullet.h"

namespace Entity {

	ECS::EntityIdType createBulletEntity(ECS::Manager* manager, Graphics* graphics, int x, int y)
	{
		ECS::EntityIdType bulletId = manager->createEntity<Bullet>();

		// Create the components
		// Create the collidable component
		Component::Collidable collidableComponent = Component::Collidable();

		// create the physics component
		Component::Physics physicsComponent = Component::Physics();

		// create the transform component
		Component::Transform transformComponent = Component::Transform();

		// create the position component
		Component::Position positionComponent = Component::Position();
		positionComponent.x = ((x + 30) * SCALE_FACTOR);
		positionComponent.y = ((y + 30) * SCALE_FACTOR);

		// create the texture component
		Component::Texture textureComponent = Component::Texture();
		if (!textureComponent.loadTexture(graphics, BULLET_IMAGE))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading bullet entity texture"));
		}
		textureComponent.visible = true;

		manager->addComponent<Component::Position>(bulletId, positionComponent);
		manager->addComponent<Component::Collidable>(bulletId, collidableComponent);
		manager->addComponent<Component::Physics>(bulletId, physicsComponent);
		manager->addComponent<Component::Transform>(bulletId, transformComponent);
		manager->addComponent<Component::Texture>(bulletId, textureComponent);

		return bulletId;
	}
}