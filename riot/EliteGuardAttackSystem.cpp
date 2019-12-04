#include "EliteGuardAttackSystem.h"

namespace System {
	void EliteGuardAttackSystem::update(float frametime) {
		// get the position of the elite guard entity
		std::unordered_set<ECS::EntityIdType>* eliteGuardPtr = this->manager->getEntities<Entity::EliteGuard>();
		for (ECS::EntityIdType id : *eliteGuardPtr)
		{
			// get the position of the elite guard
			Component::Position& positionComponent = this->manager->getEntityComponent<Component::Position>(id);
			Component::Attack& attackComponent = this->manager->getEntityComponent<Component::Attack>(id);
			Component::Texture& textureComponent = this->manager->getEntityComponent<Component::Texture>(id);
			Component::Transform& transformComponent = this->manager->getEntityComponent<Component::Transform>(id);

			attackComponent.cooldownTime -= frametime;
			if (attackComponent.cooldownTime <= 0)
			{
				// create the bullet here
				Entity::createBulletEntity(this->manager, this->graphics,
					// get the edges of the elite guard so it renders outside of the elite guard sprite by calculating the (x, y) with the size of the sprite
					positionComponent.x + (textureComponent.viewableRect.right - textureComponent.viewableRect.left),
					positionComponent.y + (textureComponent.viewableRect.bottom - textureComponent.viewableRect.top),
					transformComponent.angle
				);
				attackComponent.cooldownTime = attackComponent.interval;
			}

		}
	}
}