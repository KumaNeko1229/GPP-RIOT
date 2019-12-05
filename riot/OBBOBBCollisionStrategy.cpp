#include "OBBOBBCollisionStrategy.h"

namespace Collision {

	OBBOBBCollisionStrategy::OBBOBBCollisionStrategy() {
		this->sourceType = CollisionType::OBB;
		this->targetType = CollisionType::OBB;
	}

	bool OBBOBBCollisionStrategy::isUseable(CollisionType source, CollisionType target) {
		return (source == this->sourceType && target == this->targetType);
	}

	bool OBBOBBCollisionStrategy::isColliding(Component::Collidable source, Component::Collidable target) {
		// Sort the corners of source and target
		std::vector<D3DXVECTOR2> sourceCorners = source.getSortedCorners();
		std::vector<D3DXVECTOR2> targetCorners = target.getSortedCorners();

		// Calculate source normals
		D3DXVECTOR2 sourceXNormal = sourceCorners[1] - sourceCorners[0];
		D3DXVECTOR2 sourceYNormal = sourceCorners[2] - sourceCorners[0];

		// Check for source x extents
		std::pair<float, float> sourceXExtents = findVectorExtents(sourceCorners, sourceXNormal);
		std::pair<float, float> targetXExtents = findVectorExtents(targetCorners, sourceXNormal);

		if (!doExtentsIntersect(sourceXExtents, targetXExtents))
		{
			return false;
		}

		// Check for source y extents
		std::pair<float, float> sourceYExtents = findVectorExtents(sourceCorners, sourceYNormal);
		std::pair<float, float> targetYExtents = findVectorExtents(targetCorners, sourceYNormal);

		if (!doExtentsIntersect(sourceYExtents, sourceYExtents))
		{
			return false;
		}

		// Calculate target normals
		D3DXVECTOR2 targetXNormal = targetCorners[1] - targetCorners[0];
		D3DXVECTOR2 targetYNormal = targetCorners[2] - targetCorners[0];

		// Check for target x extents
		sourceXExtents = findVectorExtents(sourceCorners, targetXNormal);
		targetXExtents = findVectorExtents(targetCorners, targetXNormal);

		if (!doExtentsIntersect(sourceXExtents, targetXExtents))
		{
			return false;
		}

		// Check for target y extents
		sourceYExtents = findVectorExtents(sourceCorners, targetYNormal);
		targetYExtents = findVectorExtents(targetCorners, targetYNormal);

		if (!doExtentsIntersect(sourceYExtents, targetYExtents))
		{
			return false;
		}

		return true;
	}
}