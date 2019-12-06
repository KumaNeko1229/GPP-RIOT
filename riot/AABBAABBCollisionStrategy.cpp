#include "AABBAABBCollisionStrategy.h"

namespace CollisionUtil {

	AABBAABBCollisionStrategy::AABBAABBCollisionStrategy() {
		this->sourceType = CollisionType::AABB;
		this->targetType = CollisionType::AABB;
	}

	bool AABBAABBCollisionStrategy::isUseable(CollisionType source, CollisionType target) {
		return (source == this->sourceType && target == this->targetType);
	}

	bool AABBAABBCollisionStrategy::isColliding(Component::Collidable source, Component::Collidable target) {
		std::vector<D3DXVECTOR2> sourceCorners = source.getSortedCorners();
		std::vector<D3DXVECTOR2> targetCorners = target.getSortedCorners();
		return !(
			// source on the left or right of target
			sourceCorners[1].x < targetCorners[0].x || targetCorners[1].x < sourceCorners[0].x ||
			// source above or below target
			sourceCorners[2].y < targetCorners[0].y || targetCorners[2].y < sourceCorners[0].y
		);
	}

}