#include "EliteSoldierAttackSystem.h"

namespace System {
	void EliteSoldierAttackSystem::update(float frametime) {
		// get the position of the elite soldier entity
		std::unordered_set<ECS::EntityIdType>* eliteSoldierPtr = this->manager->getEntities<Entity::EliteSoldier>();
		for (ECS::EntityIdType id : *eliteSoldierPtr)
		{
			// get the position of the elite soldier
			Component::Position& positionComponent = this->manager->getEntityComponent<Component::Position>(id);
			Component::Attack& attackComponent = this->manager->getEntityComponent<Component::Attack>(id);
			Component::Texture& textureComponent = this->manager->getEntityComponent<Component::Texture>(id);
			Component::Transform& transformComponent = this->manager->getEntityComponent<Component::Transform>(id);

			attackComponent.cooldownTime -= frametime;
			if (attackComponent.cooldownTime <= 0)
			{
				// create the bullet here
				Entity::createBulletEntity(this->manager, this->graphics,
					// get the edges of the elite soldier so it renders outside of the elite soldier sprite by calculating the (x, y) with the size of the sprite
					positionComponent.x + (textureComponent.viewableRect.right - textureComponent.viewableRect.left),
					positionComponent.y + (textureComponent.viewableRect.bottom - textureComponent.viewableRect.top),
					transformComponent.angle
				);
				attackComponent.cooldownTime = attackComponent.interval;
			}

		}
	}
}