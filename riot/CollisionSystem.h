#pragma once

#include <vector>

#include "CollisionStrategy.h"
#include "CircleCircleCollisionStrategy.h"
#include "AABBAABBCollisionStrategy.h"
#include "Collidable.h"
#include "System.h"
#include "Manager.h"

namespace System {

	class CollisionSystem : public ECS::System {
		private:
			std::vector<Collision::CollisionStrategy*> strategies;
			bool colliding(Component::Collidable a, Component::Collidable b);

		public:
			void initialize();
			void update(float frameTime);
			void releaseAll();
	};

}
