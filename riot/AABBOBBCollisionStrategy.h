#pragma once

#include "vectorUtil.h"
#include "CollisionStrategy.h"

namespace Collision {

	class AABBOBBCollisionStrategy : public CollisionStrategy {
		public:
			AABBOBBCollisionStrategy();
			~AABBOBBCollisionStrategy() {};

			bool isUseable(CollisionType source, CollisionType target);
			bool isColliding(Component::Collidable source, Component::Collidable target);
	};

}
