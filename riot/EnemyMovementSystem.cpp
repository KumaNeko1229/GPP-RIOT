#include "EnemyMovementSystem.h"

namespace System {
	void EnemyMovement::update(float frameTime) {
		Component::GameState& gameState = this->manager->getComponents<Component::GameState>()->at(0);
		if (gameState.displayState == Component::DisplayState::INGAME)
		{
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
						if (inLineOfSight(playerPos, enemyPos, wallComponents))
						{
							// Move towards the player
							D3DXVECTOR2 movementVector{
								playerPos.x - enemyPos.x,
								playerPos.y - enemyPos.y
							};

							D3DXVECTOR2 normMovementVector;
							D3DXVec2Normalize(&normMovementVector, &movementVector);

							// Set the new velocity
							normMovementVector *= ENEMY_SPEED;
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

}