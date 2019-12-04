#pragma once

#include <array>
#include <vector>
#include <d3dx9math.h>
#include "CollisionStrategy.h"

namespace Collision {

	class OBBOBBCollisionStrategy : public CollisionStrategy {
		private:
			bool doExtentsIntersect(std::pair<float, float> a, std::pair<float, float> b);
			std::pair<float, float> findVectorExtents(std::vector<D3DXVECTOR2> corners, D3DXVECTOR2 normal);
		public:
			OBBOBBCollisionStrategy();
			~OBBOBBCollisionStrategy() {};

			bool isUseable(CollisionType source, CollisionType target);
			bool isColliding(Component::Collidable source, Component::Collidable target);
	};

}
