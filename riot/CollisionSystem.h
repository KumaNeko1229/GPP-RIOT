#pragma once

#include <vector>

#include "System.h"
#include "Manager.h"
#include "CollisionStrategy.h"
#include "AABBAABBCollisionStrategy.h"
#include "AABBCircleCollisionStrategy.h"
#include "AABBOBBCollisionStrategy.h"
#include "CircleCircleCollisionStrategy.h"
#include "CircleOBBCollisionStrategy.h"
#include "OBBOBBCollisionStrategy.h"
#include "CollidableComponent.h"
#include "PhysicsComponent.h"

namespace System {

	class Collision : public ECS::System {
		private:
			std::vector<CollisionUtil::CollisionStrategy*> strategies;
			bool colliding(Component::Collidable a, Component::Collidable b);

		public:
			void initialize(ECS::Manager* manager, Graphics* graphics, Input* input);
			void update(float frameTime);
			void releaseAll();
	};

}
