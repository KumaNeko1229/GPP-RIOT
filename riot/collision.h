#pragma once

#include <d3d9.h>
#include <functional>

enum class CollisionType {
	CIRCLE,
	AABB,
	OBB,
};

class Collidable {
	protected:
		CollisionType collisionType;
		float radius;
		RECT edges;
		int centerX;
		int centerY;
	public:
		Collidable();
		Collidable(CollisionType collisionType, float radius, RECT edges, int centerX, int centerY);
		~Collidable();

		CollisionType getCollisionType() { return this->collisionType; };
		float getRadius() { return this->radius; };
		RECT getEdges() { return this->edges; };
		int getCenterX() { return this->centerX; };
		int getCenterY() { return this->centerY; };

		bool collidesWith(Collidable collidable);
};

std::function<bool(Collidable, Collidable)> findCollisionDetector(CollisionType a, CollisionType b);

bool CircleCircleCheckCollision(Collidable a, Collidable b);

