#pragma once

#include <d3dx9math.h>
#include "vectorUtil.h"
#include "CollisionStrategy.h"

namespace Collision {

	class CircleOBBCollisionStrategy : public CollisionStrategy {
		public:
			CircleOBBCollisionStrategy();
			~CircleOBBCollisionStrategy() {};

			bool isUseable(CollisionType source, CollisionType target);
			bool isColliding(Component::Collidable source, Component::Collidable target);
	};

}
