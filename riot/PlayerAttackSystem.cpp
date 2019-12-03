#include "PlayerAttackSystem.h"

namespace System {

	// check for the timer, and create the bullets here
	void PlayerAttackSystem::update(float frameTime)
	{
		// get the position of the player entity
		std::unordered_set<ECS::EntityIdType>* playerPtrs = this->manager->getEntities<Entity::Player>();
		for (ECS::EntityIdType id : *playerPtrs)
		{
			// get the position of the player
			Component::Position& positionComponent = this->manager->getEntityComponent<Component::Position>(id);
			Component::Attack& attackComponent = this->manager->getEntityComponent<Component::Attack>(id);
			Component::Texture& textureComponent = this->manager->getEntityComponent<Component::Texture>(id);
			Component::Transform& transformComponent = this->manager->getEntityComponent<Component::Transform>(id);

			if (input->getMouseLButton())
			{
				attackComponent.cooldownTime -= frameTime;
				if (attackComponent.cooldownTime <= 0)
				{
					// create the bullet here
					Entity::createBulletEntity(this->manager, this->graphics,
						// get the edges of the player so it renders outside of the player sprite by calculating the (x, y) with the size of the sprite
						positionComponent.x + (textureComponent.viewableRect.right - textureComponent.viewableRect.left),
						positionComponent.y + (textureComponent.viewableRect.bottom - textureComponent.viewableRect.top),
						transformComponent.angle
					);
					attackComponent.cooldownTime = attackComponent.interval;
				}
			}

			input->setMouseLButton(FALSE);
		}
	}
}
