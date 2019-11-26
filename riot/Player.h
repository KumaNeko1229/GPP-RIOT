#pragma once

class Player {

	private:
		// variables
		int health;
		float velocity; // side to side and up down velocity is the same for simplicity

	public:
		// Constructor
		Player();
		// Destructor
		~Player();

		void shoot();
		bool checkWeaponCollision();
		int getHealth() { return this->health; }
		float getVelocity() { return this->velocity; }
};
