
#include "riot.h"

//=============================================================================
// Constructor
//=============================================================================
Riot::Riot() {}

//=============================================================================
// Destructor
//=============================================================================
Riot::~Riot()
{
	releaseAll();           // call onLostDevice() for every graphics item
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void Riot::initialize(HWND hwnd)
{
	Game::initialize(hwnd); // throws GameError
	if (!playerTexture.initialize(graphics, PLAYER_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player texture"));
	// use full image for now
	if (!playerImage.initialize(graphics, 0, 0, 0, &playerTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player"));
	player = Player::Player(&playerImage);

	return;
}

//=============================================================================
// Update all game items
//=============================================================================
void Riot::update() 
{	
	// does not take deltatime into account yet
	if (input->isKeyDown(UP_KEY))
	{
		playerImage.setY(playerImage.getY() - player.getVelocity());
	}
	if (input->isKeyDown(DOWN_KEY))
	{
		playerImage.setY(playerImage.getY() + player.getVelocity());
	}
	if (input->isKeyDown(LEFT_KEY))
	{
		playerImage.setX(playerImage.getX() - player.getVelocity());
	}
	if (input->isKeyDown(RIGHT_KEY))
	{
		playerImage.setX(playerImage.getX() + player.getVelocity());
	}
}

//=============================================================================
// Artificial Intelligence
//=============================================================================
void Riot::ai() {}

//=============================================================================
// Handle collisions
//=============================================================================
void Riot::collisions() {}

//=============================================================================
// Render game items
//=============================================================================
void Riot::render()
{
	graphics->spriteBegin();                // begin drawing sprites

	player.draw();

	graphics->spriteEnd();                  // end drawing sprites
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void Riot::releaseAll()
{
	Game::releaseAll();
	return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void Riot::resetAll()
{
	Game::resetAll();
	return;
}