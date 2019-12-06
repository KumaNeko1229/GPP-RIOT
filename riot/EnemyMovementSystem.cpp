#include "EnemyMovementSystem.h"

namespace System {
	bool withinRange(float a, float b, float value)
	{
		if (a < b)
		{
			return (a < value) && (value < b);
		}
		else
		{
			return (b < value) && (value < a);
		}
	}

	bool EnemyMovement::inLineOfSight(
		Component::Position playerPos,
		Component::Position enemyPos,
		std::forward_list<Component::Collidable> walls
	)
	{
		// Calculate the gradient between the enemy and player
		float gradient = (playerPos.y - enemyPos.y)/(playerPos.x - enemyPos.x);
		for (Component::Collidable& wall : walls)
		{
			std::vector<D3DXVECTOR2> sortedCorners = wall.getSortedCorners();

			// Check if wall is between the player and the enemy position
			bool isBetween = false;
			for (D3DXVECTOR2 corner : sortedCorners)
			{
				if (withinRange(playerPos.x, enemyPos.x, corner.x))
				{
					isBetween = true;
					break;
				}

				if (withinRange(playerPos.y, enemyPos.y, corner.y))
				{
					isBetween = true;
					break;
				}
			}

			if (!isBetween)
			{
				continue;
			}

			D3DXVECTOR2& bottomLeftCorner = sortedCorners[3];
			D3DXVECTOR2& topRightCorner = sortedCorners[1];

			// Check using bottom left corner
			float y = gradient * (bottomLeftCorner.x - playerPos.x) + playerPos.y;
			if (gradient >= INFINITY)
			{
				y = sortedCorners[0].y;
			}
			float x = (bottomLeftCorner.y - playerPos.y)/gradient + playerPos.x;

			// Check if the x intersects the bottom of the wall
			if (sortedCorners[3].x <= x && x <= sortedCorners[2].x)
			{
				return false;
			}

			// Check if the y intersects the left of the wall
			if (sortedCorners[0].y <= y && y <= sortedCorners[3].y)
			{
				return false;
			}

			// Calculate the new x for the right of the wall
			y = gradient * (topRightCorner.x - playerPos.x) + playerPos.y;
			if (sortedCorners[1].y < y && y < sortedCorners[2].y)
			{
				return false;
			}
		}

		return true;
	}

	void EnemyMovement::update(float frameTime) {
		std::vector<ECS::Types::TypeId> enemyTypes;
		enemyTypes.push_back(ECS::Types::toTypeId<Entity::Blocker>());
		enemyTypes.push_back(ECS::Types::toTypeId<Entity::Guard>());
		enemyTypes.push_back(ECS::Types::toTypeId<Entity::EliteGuard>());
		enemyTypes.push_back(ECS::Types::toTypeId<Entity::EliteSoldier>());

		// Get all the walls
		std::unordered_set<ECS::EntityIdType>* wallIds = this->manager->getEntities<Entity::Wall>();
		std::forward_list<Component::Collidable> wallComponents;
		for (ECS::EntityIdType wallId : *wallIds)
		{
			wallComponents.push_front(this->manager->getEntityComponent<Component::Collidable>(wallId));
		}

		for (ECS::EntityIdType playerEntityId : *this->manager->getEntities<Entity::Player>())
		{
			Component::Position& playerPos = this->manager->getEntityComponent<Component::Position>(playerEntityId);

			for (ECS::Types::TypeId enemyType : enemyTypes)
			{
				for (ECS::EntityIdType enemyEntityId : *this->manager->getEntities(enemyType))
				{
					Component::Position& enemyPos = this->manager->getEntityComponent<Component::Position>(enemyEntityId);
					// Check if the player is in line of sight
					Component::Physics& enemyPhysics = this->manager->getEntityComponent<Component::Physics>(enemyEntityId);
					if (this->inLineOfSight(playerPos, enemyPos, wallComponents))
					{
						// Move towards the player
						D3DXVECTOR2 movementVector {
							playerPos.x - enemyPos.x,
							playerPos.y - enemyPos.y
						};

						D3DXVECTOR2 normMovementVector;
						D3DXVec2Normalize(&normMovementVector, &movementVector);

						// Set the new velocity
						normMovementVector *= ENEMY_SPEED * frameTime;
						enemyPhysics.velocityX = normMovementVector.x;
						enemyPhysics.velocityY = normMovementVector.y;
					}
					else
					{
						enemyPhysics.velocityX = 0;
						enemyPhysics.velocityY = 0;
					}
				}
			}
		}
	}

}