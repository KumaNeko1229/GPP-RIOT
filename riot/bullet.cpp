#include "bullet.h"

namespace Entity {

	ECS::EntityIdType createBulletEntity(ECS::Manager* manager, Graphics graphics)
	{
		ECS::EntityIdType bulletId = manager->createEntity<Bullet>();

		// Create the components
		// create the physics component
		Component::Physics physicsComponent = Component::Physics();

		// create the transform component
		Component::Transform transformComponent = Component::Transform();

		// create the position component
		Component::Position positionComponent = Component::Position();

		// create the texture component

		manager->addComponent<Component::Position>(bulletId, positionComponent);
		manager->addComponent<Component::Physics>(bulletId, physicsComponent);
		manager->addComponent<Component::Transform>(bulletId, transformComponent);

		return bulletId;
	}
}