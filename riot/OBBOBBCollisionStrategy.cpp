#include "OBBOBBCollisionStrategy.h"

namespace Collision {

	bool OBBOBBCollisionStrategy::doExtentsIntersect(std::pair<float, float> a, std::pair<float, float> b) {
		return !(
			// a less than b
			a.second < b.first ||
			// a more than b
			b.second < a.first
		);
	}

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
		std::vector<D3DXVECTOR2> sourceCorners = source.getSortedCorners();
		std::vector<D3DXVECTOR2> targetCorners = target.getSortedCorners();

		// Calculate source normals
		D3DXVECTOR2 sourceXNormal = sourceCorners[1] - sourceCorners[0];
		D3DXVECTOR2 sourceYNormal = sourceCorners[2] - sourceCorners[0];

		// Check for source x extents
		std::pair<float, float> sourceXExtents = this->findVectorExtents(sourceCorners, sourceXNormal);
		std::pair<float, float> targetXExtents = this->findVectorExtents(targetCorners, sourceXNormal);

		if (!this->doExtentsIntersect(sourceXExtents, targetXExtents))
		{
			return false;
		}

		// Check for source y extents
		std::pair<float, float> sourceYExtents = this->findVectorExtents(sourceCorners, sourceYNormal);
		std::pair<float, float> targetYExtents = this->findVectorExtents(targetCorners, sourceYNormal);

		if (!this->doExtentsIntersect(sourceYExtents, sourceYExtents))
		{
			return false;
		}

		// Calculate target normals
		D3DXVECTOR2 targetXNormal = targetCorners[1] - targetCorners[0];
		D3DXVECTOR2 targetYNormal = targetCorners[2] - targetCorners[0];

		// Check for target x extents
		sourceXExtents = this->findVectorExtents(sourceCorners, targetXNormal);
		targetXExtents = this->findVectorExtents(targetCorners, targetXNormal);

		if (!this->doExtentsIntersect(sourceXExtents, targetXExtents))
		{
			return false;
		}

		// Check for target y extents
		sourceYExtents = this->findVectorExtents(sourceCorners, targetYNormal);
		targetYExtents = this->findVectorExtents(targetCorners, targetYNormal);

		if (!this->doExtentsIntersect(sourceYExtents, targetYExtents))
		{
			return false;
		}

		return true;
	}
}