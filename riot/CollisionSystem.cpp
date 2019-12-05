#include "CollisionSystem.h"

namespace System {

	bool Collision::colliding(Component::Collidable a, Component::Collidable b) {
		for (CollisionUtil::CollisionStrategy* strategy : this->strategies)
		{
			// Look for a strategy to handle this collision
			if (strategy->isUseable(a.collisionType, b.collisionType))
			{
				return strategy->isColliding(a, b);
			}
		}

		// No strategy found, throw an error
		throw(GameError(gameErrorNS::FATAL_ERROR, "Unable to find collision strategy to handle collision."));
	}

	void Collision::initialize(ECS::Manager* manager, Graphics* graphics, Input* input) {
		System::initialize(manager, graphics, input);
		// Add the collision strategies
		this->strategies.push_back(new CollisionUtil::AABBAABBCollisionStrategy());
		this->strategies.push_back(new CollisionUtil::AABBCircleCollisionStrategy());
		this->strategies.push_back(new CollisionUtil::AABBOBBCollisionStrategy());
		this->strategies.push_back(new CollisionUtil::CircleCircleCollisionStrategy());
		this->strategies.push_back(new CollisionUtil::CircleOBBCollisionStrategy());
		this->strategies.push_back(new CollisionUtil::OBBOBBCollisionStrategy());
	}

	void Collision::update(float frameTime) {
		// Get all animatable components
		std::vector<Component::Collidable>* componentsPtr =
			this->manager->getComponents<Component::Collidable>();

		for (std::size_t i = 0; i < componentsPtr->size(); i++)
		{
			for (std::size_t j = i+1; j < componentsPtr->size(); j++)
			{
				// Source collidable object
				Component::Collidable& source = componentsPtr->at(i);
				Component::Collidable& target = componentsPtr->at(j);

				// Skip checks if the two objects cannot move (do not have physics component)
				if (!this->manager->entityHasComponent<Component::Physics>(source.entityId) &&
					!this->manager->entityHasComponent<Component::Physics>(target.entityId))
				{
					continue;
				}

				// Check if the entities are already colliding with each other
				bool wasColliding =
					source.collidingWith.find(target.entityId) != source.collidingWith.end();
				bool isColliding = this->colliding(source, target);

				if (!wasColliding && isColliding)
				{
					source.collidingWith.insert(target.entityId);
					target.collidingWith.insert(source.entityId);
					source.onEnter(this->manager, target.entityId);
					target.onEnter(this->manager, source.entityId);
				}
				else if (wasColliding && isColliding)
				{
					source.onStay(this->manager, target.entityId, frameTime);
					target.onStay(this->manager, source.entityId, frameTime);
				}
				else
				{
					source.collidingWith.erase(target.entityId);
					target.collidingWith.erase(source.entityId);
					source.onExit(this->manager, target.entityId);
					target.onExit(this->manager, source.entityId);
				}
			}
		}
	}

	void Collision::releaseAll() {
		// Delete all the strategies
		for (CollisionUtil::CollisionStrategy* strategy : this->strategies)
		{
			SAFE_DELETE(strategy);
		}
	}
}