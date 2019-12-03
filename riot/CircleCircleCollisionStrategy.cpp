#include "CircleCircleCollisionStrategy.h"

namespace Collision {

	CircleCircleCollisionStrategy::CircleCircleCollisionStrategy() {
		this->sourceType = CollisionType::CIRCLE;
		this->targetType = CollisionType::CIRCLE;
	}

	bool CircleCircleCollisionStrategy::isUseable(CollisionType source, CollisionType target) {
		if (source == this->sourceType && source == this->targetType)
		{
			return true;
		}

		return false;
	}

	bool CircleCircleCollisionStrategy::isColliding(Component::Collidable source, Component::Collidable target) {
		// Find the difference between the centers
		int xDiff = source.getXCenter() - target.getXCenter();
		int yDiff = source.getYCenter() - target.getYCenter();

		// Square both differences
		xDiff *= xDiff;
		yDiff *= yDiff;

		float radiiSquared = source.radius + target.radius;
		radiiSquared *= radiiSquared;

		return (xDiff + yDiff) < radiiSquared;
	}
}