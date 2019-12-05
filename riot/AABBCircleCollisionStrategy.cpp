#include "AABBCircleCollisionStrategy.h"

namespace Collision {

	AABBCircleCollisionStrategy::AABBCircleCollisionStrategy() {
		this->sourceType = CollisionType::AABB;
		this->targetType = CollisionType::CIRCLE;
	}

	bool AABBCircleCollisionStrategy::isUseable(CollisionType source, CollisionType target) {
		return ((source == this->sourceType && target == this->targetType) ||
				(target == this->sourceType && source == this->targetType));
	}

	bool AABBCircleCollisionStrategy::isColliding(Component::Collidable source, Component::Collidable target) {
		// Determine which is circle and which is aabb
		Component::Collidable* circle = &source;
		Component::Collidable* aabb = &target;

		if (source.collisionType == CollisionType::AABB)
		{
			circle = &target;
			aabb = &source;
		}

		// Check if the circle is in the voronoi region
		D3DXVECTOR2 circleCenter = circle->getCenter();
		std::vector<D3DXVECTOR2> sortedCorners = aabb->getSortedCorners();
		char voronoiQuadrants[] = {2, 1, 4, 3};

		for (char i = 0; i < 4; i++)
		{
			if (getQuadrant(circleCenter, sortedCorners[i]) == voronoiQuadrants[i])
			{
				return (circle->radius * circle->radius) > distance2(circleCenter, sortedCorners[i]);
			}
		}

		// Find the normals of aabb
		D3DXVECTOR2 xNormal = sortedCorners[1] - sortedCorners[0];
		D3DXVECTOR2 yNormal = sortedCorners[2] - sortedCorners[0];

		std::pair<float, float> aabbXExtents = findVectorExtents(sortedCorners, xNormal);
		std::pair<float, float> circleXExtents {circleCenter.x - circle->radius, circleCenter.x + circle->radius};

		if (doExtentsIntersect(aabbXExtents, circleXExtents))
		{
			return true;
		}

		std::pair<float, float> aabbYExtents = findVectorExtents(sortedCorners, yNormal);
		std::pair<float, float> circleYExtents {circleCenter.y - circle->radius, circleCenter.y + circle->radius};

		if (doExtentsIntersect(aabbYExtents, circleYExtents))
		{
			return true;
		}

		return false;
	}

}