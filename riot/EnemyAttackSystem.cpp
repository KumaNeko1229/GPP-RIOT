#include "EnemyAttackSystem.h"

namespace System {

	void EnemyAttack::update(float frametime) {

		// get all the walls and read the positions
		// Get all the walls
		std::unordered_set<ECS::EntityIdType>* wallIds = this->manager->getEntities<Entity::Wall>();
		std::forward_list<Component::Collidable> wallComponents;
		for (ECS::EntityIdType wallId : *wallIds)
		{
			wallComponents.push_front(this->manager->getEntityComponent<Component::Collidable>(wallId));
		}

		// get each of the individual entities involved
		std::unordered_set<ECS::EntityIdType>* blockerPtrs = this->manager->getEntities<Entity::Blocker>();
		std::unordered_set<ECS::EntityIdType>* guardPtrs = this->manager->getEntities<Entity::Guard>();
		std::unordered_set<ECS::EntityIdType>* eliteGuardPtrs = this->manager->getEntities<Entity::EliteGuard>();
		std::unordered_set<ECS::EntityIdType>* eliteSoldierPtrs = this->manager->getEntities<Entity::EliteSoldier>();
		std::unordered_set<ECS::EntityIdType>* playerPtr = this->manager->getEntities<Entity::Player>();

		for (ECS::EntityIdType bid : *blockerPtrs)
		{
			Component::Position& positionComponent = this->manager->getEntityComponent<Component::Position>(bid);
			Component::Attack& attackComponent = this->manager->getEntityComponent<Component::Attack>(bid);
			Component::Texture& textureComponent = this->manager->getEntityComponent<Component::Texture>(bid);
			Component::Transform& transformComponent = this->manager->getEntityComponent<Component::Transform>(bid);

			for (ECS::EntityIdType Pid : *playerPtr) {
				Component::Position& playerPositionComponent = this->manager->getEntityComponent<Component::Position>(Pid);

				attackComponent.cooldownTime -= frametime;
				if (attackComponent.cooldownTime <= 0)
				{
					// deal damage as blocker
					attackComponent.cooldownTime = attackComponent.interval;
				}
			}
		}

		for (ECS::EntityIdType gid : *guardPtrs)
		{
			Component::Position& positionComponent = this->manager->getEntityComponent<Component::Position>(gid);
			Component::Attack& attackComponent = this->manager->getEntityComponent<Component::Attack>(gid);
			Component::Texture& textureComponent = this->manager->getEntityComponent<Component::Texture>(gid);
			Component::Transform& transformComponent = this->manager->getEntityComponent<Component::Transform>(gid);

			for (ECS::EntityIdType Pid : *playerPtr) {
				Component::Position& playerPositionComponent = this->manager->getEntityComponent<Component::Position>(Pid);

				attackComponent.cooldownTime -= frametime;
				if (attackComponent.cooldownTime <= 0)
				{
					if (checkForRange(attackComponent.range, playerPositionComponent, positionComponent) && inLineOfSight(playerPositionComponent, positionComponent, wallComponents))
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

		for (ECS::EntityIdType egid : *eliteGuardPtrs)
		{
			Component::Position& positionComponent = this->manager->getEntityComponent<Component::Position>(egid);
			Component::Attack& attackComponent = this->manager->getEntityComponent<Component::Attack>(egid);
			Component::Texture& textureComponent = this->manager->getEntityComponent<Component::Texture>(egid);
			Component::Transform& transformComponent = this->manager->getEntityComponent<Component::Transform>(egid);

			for (ECS::EntityIdType Pid : *playerPtr) {
				Component::Position& playerPositionComponent = this->manager->getEntityComponent<Component::Position>(Pid);

				attackComponent.cooldownTime -= frametime;
				if (attackComponent.cooldownTime <= 0)
				{
					if (checkForRange(attackComponent.range, playerPositionComponent, positionComponent) && inLineOfSight(playerPositionComponent, positionComponent, wallComponents))
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


		for (ECS::EntityIdType esid : *guardPtrs)
		{
			Component::Position& positionComponent = this->manager->getEntityComponent<Component::Position>(esid);
			Component::Attack& attackComponent = this->manager->getEntityComponent<Component::Attack>(esid);
			Component::Texture& textureComponent = this->manager->getEntityComponent<Component::Texture>(esid);
			Component::Transform& transformComponent = this->manager->getEntityComponent<Component::Transform>(esid);

			for (ECS::EntityIdType Pid : *playerPtr) {
				Component::Position& playerPositionComponent = this->manager->getEntityComponent<Component::Position>(Pid);

				attackComponent.cooldownTime -= frametime;
				if (attackComponent.cooldownTime <= 0)
				{
					if (checkForRange(attackComponent.range, playerPositionComponent, positionComponent) && inLineOfSight(playerPositionComponent, positionComponent, wallComponents))
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
						Entity::createMetalBulletEntity(this->manager, this->graphics, bulletPositionX, bulletPositionY, transformComponent.angle, bulletAngle);

						// reset the bullet cooldown
						attackComponent.cooldownTime = attackComponent.interval;
					}
				}
			}
		}
	}
}