
#include "riot.h"
#include "player.h"

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
	this->manager = new ECS::Manager();

	Entity::createPlayerEntity(this->manager, this->graphics);

	// TODO: Create the systems and register them to the manager
	this->systemRunner.registerSystem(new System::AnimationSystem());
	this->systemRunner.registerSystem(new System::CollisionSystem());
	this->systemRunner.registerSystem(new System::RenderSystem());
	this->systemRunner.registerSystem(new System::MovementSystem());
	this->systemRunner.registerSystem(new System::PlayerMovementSystem());
	this->systemRunner.registerSystem(new System::PlayerAttackSystem());
	this->systemRunner.registerSystem(new System::MenuSystem());
	this->systemRunner.initialize(this->manager, this->graphics, this->input);
}

//=============================================================================
// Update all game items
//=============================================================================
void Riot::update() {
	this->systemRunner.update(this->frameTime);
}

//=============================================================================
// Render game items
//=============================================================================
void Riot::render()
{
	graphics->spriteBegin();                // begin drawing sprites

	this->systemRunner.render();

	graphics->spriteEnd();                  // end drawing sprites
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void Riot::releaseAll()
{
	this->systemRunner.releaseAll();
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

	this->systemRunner.resetAll();
}