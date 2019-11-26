#pragma once

#include "image.h"
#include "collision.h"

class Entity {

	protected:
		Image* image;
		Collidable collidable;

	public:
		Entity();
		Entity(Image* image, CollisionType collisionType);
		virtual ~Entity();

		Image* getImagePtr() { return this->image; }
		void draw() { image->draw(); return;  }
		Collidable getCollidable() { return this->collidable; };

		bool collidesWith(Entity* entity);
};
