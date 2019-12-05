#pragma once

#include <vector>

#include "CollisionStrategy.h"
#include "AABBAABBCollisionStrategy.h"
#include "AABBCircleCollisionStrategy.h"
#include "AABBOBBCollisionStrategy.h"
#include "CircleCircleCollisionStrategy.h"
#include "CircleOBBCollisionStrategy.h"
#include "OBBOBBCollisionStrategy.h"
#include "Collidable.h"
#include "System.h"
#include "Manager.h"

namespace System {

	class CollisionSystem : public ECS::System {
		private:
			std::vector<Collision::CollisionStrategy*> strategies;
			bool colliding(Component::Collidable a, Component::Collidable b);

		public:
			void initialize(ECS::Manager* manager, Graphics* graphics, Input* input);
			void update(float frameTime);
			void releaseAll();
	};

}
