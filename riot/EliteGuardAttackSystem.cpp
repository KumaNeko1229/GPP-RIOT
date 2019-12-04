#include "EliteGuardAttackSystem.h"

namespace System {
	void EliteGuardAttackSystem::update(float frametime) {

		std::unordered_set<ECS::EntityIdType>* eliteGuardPtrs = this->manager->getEntities<Entity::EliteGuard>();
		std::unordered_set<ECS::EntityIdType>* playerPtr = this->manager->getEntities<Entity::Player>();

		for (ECS::EntityIdType id : *eliteGuardPtrs)
		{
			// get the position of the elite guard
			Component::Position& positionComponent = this->manager->getEntityComponent<Component::Position>(id);
			Component::Attack& attackComponent = this->manager->getEntityComponent<Component::Attack>(id);
			Component::Texture& textureComponent = this->manager->getEntityComponent<Component::Texture>(id);
			Component::Transform& transformComponent = this->manager->getEntityComponent<Component::Transform>(id);

			for (ECS::EntityIdType Pid : *playerPtr) {
				Component::Position& playerPositionComponent = this->manager->getEntityComponent<Component::Position>(Pid);

				attackComponent.cooldownTime -= frametime;
				if (attackComponent.cooldownTime <= 0)
				{
					float bulletAngle = 0;
					float yDiff = playerPositionComponent.y - positionComponent.y - (textureComponent.viewableRect.bottom - textureComponent.viewableRect.top) / 2;
					float xDiff = playerPositionComponent.x - positionComponent.x - (textureComponent.viewableRect.right - textureComponent.viewableRect.left) / 2;

					if (!(xDiff == 0 && yDiff == 0))
					{
						bulletAngle = atan(yDiff / xDiff);
					}

					if (xDiff < 0)
					{
						const int ySign = (yDiff < 0) ? -1 : 1;
						bulletAngle = atan(yDiff / xDiff) + PI * ySign;
					}

					// in case the division to get the centre returns a 0.5
					float bulletPositionX = 0.0f;
					float bulletPositionY = 0.0f;
					// get the centre of the player so it renders outside of the player sprite by calculating the (x, y) with the size of the sprite, and corrections made
					// for the spritesheet whitespace, not pixel-perfect for simplicity
					if (transformComponent.angle == UP_ANGLE)
					{
						bulletPositionX = positionComponent.x + (textureComponent.viewableRect.right - textureComponent.viewableRect.left) / 2;
						bulletPositionY = positionComponent.y;
					}
					if (transformComponent.angle == DOWN_ANGLE)
					{
						bulletPositionX = positionComponent.x + (textureComponent.viewableRect.right - textureComponent.viewableRect.left) / 2;
						bulletPositionY = positionComponent.y + (textureComponent.viewableRect.bottom - textureComponent.viewableRect.top);
					}
					if (transformComponent.angle == RIGHT_ANGLE)
					{
						bulletPositionX = positionComponent.x + (textureComponent.viewableRect.right - textureComponent.viewableRect.left);
						bulletPositionY = positionComponent.y;
					}
					if (transformComponent.angle == LEFT_ANGLE)
					{
						bulletPositionX = positionComponent.x;
						bulletPositionY = positionComponent.y;
					}

					if (0 >= bulletAngle && bulletAngle >= -(PI / 2))
					{
						transformComponent.angle = UP_ANGLE;
					}
					if ((-PI / 2) >= bulletAngle && bulletAngle >= -(PI))
					{
						transformComponent.angle = LEFT_ANGLE;
					}
					if ((PI / 2) <= bulletAngle && bulletAngle <= PI)
					{
						transformComponent.angle = DOWN_ANGLE;
					}
					if (0 <= bulletAngle && bulletAngle <= (PI / 2))
					{
						transformComponent.angle = RIGHT_ANGLE;
					}

					// create the bullet here
					Entity::createRubberBulletEntity(this->manager, this->graphics, bulletPositionX, bulletPositionY, transformComponent.angle, bulletAngle);

					// reset the bullet cooldown
					attackComponent.cooldownTime = attackComponent.interval;
				}
			}
		}
	}
}