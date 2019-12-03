#pragma once

#include "CollisionStrategy.h"

namespace Collision {

	class CircleCircleCollisionStrategy : public CollisionStrategy {
		public:
			CircleCircleCollisionStrategy();
			~CircleCircleCollisionStrategy() {};

			bool isUseable(CollisionType source, CollisionType target);
			bool isColliding(Component::Collidable source, Component::Collidable target);
	};

}
