#include "entity.h"

Entity::Entity() {
	image = NULL;
}

Entity::Entity(Image* image, CollisionType collisionType) {
	this->image = image;

	// Calculate half of image height and width
	float halfHeight = (image->getHeight() * image->getScale()) / 2.0;
	float halfWidth = (image->getWidth() * image->getScale()) / 2.0;

	// Get the edges regardless of getX or getY's positioning
	RECT imageEdges;
	imageEdges.top = image->getCenterY() - halfHeight;
	imageEdges.left = image->getCenterX() - halfWidth;
	imageEdges.bottom = image->getCenterY() + halfHeight;
	imageEdges.right = image->getCenterX() + halfWidth;

	Collidable collidable = Collidable(
		collisionType,
		// Arbitrarily assign the width as the radius
		halfWidth,
		imageEdges,
		image->getCenterX(),
		image->getCenterY()
	);

	this->collidable = collidable;
}

Entity::~Entity() {}

bool Entity::collidesWith(Entity* entity) {
	this->collidable.collidesWith(entity->getCollidable());

	return true;
}
