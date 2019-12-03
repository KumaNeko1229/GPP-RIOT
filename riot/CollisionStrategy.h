#pragma once

#include "Position.h"
#include "CollisionType.h"
#include "Collidable.h"

namespace Collision {

	class CollisionStrategy {
		protected:
			CollisionType sourceType;
			CollisionType targetType;
		public:
			virtual bool isUseable(CollisionType source, CollisionType target) = 0;
			virtual bool isColliding(Component::Collidable source, Component::Collidable target) = 0;
	};

}
