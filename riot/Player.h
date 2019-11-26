#pragma once
#include "entity.h"

class Player : Entity {

	private:
		// variables
		int health;
		float velocity; // side to side and up down velocity is the same for simplicity

	public:
		// Constructor
		Player();
		Player(Image* i);
		// Destructor
		~Player();

		void shoot();
		void draw() { Entity::draw(); }
		bool checkWeaponCollision();
		int getHealth() { return this->health; }
		float getVelocity() { return this->velocity; }
};
