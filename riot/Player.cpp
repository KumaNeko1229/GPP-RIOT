#include "Player.h"

// default left for now
Player::Player() 
{
	health = 20;
	velocity = 20.0f;
}

Player::Player(Image* i)
{
	health = 20;
	velocity = 20.0f;
	image = i;
}
