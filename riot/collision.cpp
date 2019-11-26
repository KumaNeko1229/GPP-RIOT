#include "collision.h"

Collidable::Collidable() {}

Collidable::Collidable(CollisionType collisionType, float radius, RECT edges, int centerX, int centerY) {
	this->collisionType = collisionType;
	this->radius = radius;
	this->edges = edges;
	this->centerX = centerX;
	this->centerY = centerY;
}

Collidable::~Collidable() {}

bool Collidable::collidesWith(Collidable collidable) {
	return findCollisionDetector(
		this->getCollisionType(),
		collidable.getCollisionType()
	)(*this, collidable);
}

// Collision detectors
std::function<bool(Collidable, Collidable)> findCollisionDetector(CollisionType a, CollisionType b) {
	if (a == CollisionType::CIRCLE && b == CollisionType::CIRCLE) {
		return CircleCircleCheckCollision;
	}
}

bool CircleCircleCheckCollision(Collidable a, Collidable b) {
	// Find the difference between the centers
	int xDiff = b.getCenterX() - a.getCenterX();
	int yDiff = b.getCenterY() - a.getCenterY();

	// Square both differences
	xDiff *= xDiff;
	yDiff *= yDiff;

	float radiiSquared = (a.getRadius() + b.getRadius());
	radiiSquared *= radiiSquared;

	return (xDiff + yDiff) < radiiSquared;
}
