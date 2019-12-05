#pragma once

#include "vectorUtil.h"
#include "CollisionStrategy.h"

namespace Collision {

	class AABBCircleCollisionStrategy : public CollisionStrategy {
		public:
			AABBCircleCollisionStrategy();
			~AABBCircleCollisionStrategy() {};

			bool isUseable(CollisionType source, CollisionType target);
			bool isColliding(Component::Collidable source, Component::Collidable target);
	};

}
