#include "OBBOBBCollisionStrategy.h"

namespace Collision {

	std::pair<float, float> OBBOBBCollisionStrategy::findVectorExtents(std::vector<D3DXVECTOR2> corners, D3DXVECTOR2 normal) {
		float min = INFINITY;
		float max = -INFINITY;

		for (D3DXVECTOR2 corner : corners)
		{
			float projection = D3DXVec2Dot(&corner, &normal);

			if (projection > max)
			{
				max = projection;
			}
			else if (projection < min)
			{
				min = projection;
			}
		}

		return std::pair<float, float>(min, max);
	}


	OBBOBBCollisionStrategy::OBBOBBCollisionStrategy() {
		this->sourceType = CollisionType::OBB;
		this->targetType = CollisionType::OBB;
	}

	bool OBBOBBCollisionStrategy::isUseable(CollisionType source, CollisionType target) {
		return (source == this->sourceType && source == this->targetType);
	}

	bool OBBOBBCollisionStrategy::isColliding(Component::Collidable source, Component::Collidable target) {
		// Sort the corners of source and target
		std::array<D3DXVECTOR2, 4> sourceCorners = source.getSortedCorners();
		std::array<D3DXVECTOR2, 4> targetCorners = target.getSortedCorners();

		// Calculate source normals
		D3DXVECTOR2 sourceXNormal = sourceCorners[1] - sourceCorners[0];
		D3DXVECTOR2 sourceYNormal = sourceCorners[2] - sourceCorners[0];

		std::pair<float, float> sourceXExtents = this->findVectorExtents(sourceCorners, sourceXNormal);
		float sourceSourceXMax = source.corners[1].x;
		float sourceSourceXMin = source.corners[0].x;
		float sourceSourceYMax = source.corners[2].y;
		float sourceSourceYMin = source.corners[0].y;

		// Project all points onto source normals to find max and min

		// Find maximum point of projected point for source
		// Find minimum point of projected point for source
		// Find maximum point of projected point for target
		// Find minimum point of projected point for target
	}
}