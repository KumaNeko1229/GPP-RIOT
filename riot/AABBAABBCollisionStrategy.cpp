#include "AABBAABBCollisionStrategy.h"

namespace Collision {

	AABBAABBCollisionStrategy::AABBAABBCollisionStrategy() {
		this->sourceType = CollisionType::AABB;
		this->targetType = CollisionType::AABB;
	}

	bool AABBAABBCollisionStrategy::isUseable(CollisionType source, CollisionType target) {
		if (source == this->sourceType && source == this->targetType)
		{
		return true;
		}

		return false;
	}

	bool AABBAABBCollisionStrategy::isColliding(Component::Collidable source, Component::Collidable target) {
		return !(
			// source on the left or right of target
			source.edges.right < target.edges.left || target.edges.right < source.edges.left ||
			// source above or below target
			source.edges.top < target.edges.bottom || target.edges.top < source.edges.bottom
		);
	}

}