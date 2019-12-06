
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
	this->manager = new ECS::Manager();
	// TODO: Create the systems and register them to the manager

	this->systemRunner.registerSystem(new System::GameState());
	//this->systemRunner.registerSystem(new System::Menu());
	//this->systemRunner.registerSystem(new System::Animation());
	//this->systemRunner.registerSystem(new System::Collision());
	//this->systemRunner.registerSystem(new System::Render());
	//this->systemRunner.registerSystem(new System::Movement());
	//this->systemRunner.registerSystem(new System::PlayerMovement());
	//this->systemRunner.registerSystem(new System::PlayerAttack());
	//this->systemRunner.registerSystem(new System::HUD());

	this->systemRunner.registerSystem(new System::PauseMenu());
	this->systemRunner.registerSystem(new System::Render());
	this->systemRunner.registerSystem(new System::TextSystem());
	this->systemRunner.registerSystem(new System::ClickSystem());

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
	SAFE_DELETE(this->manager);
	Game::releaseAll();
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