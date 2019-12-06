#include "PauseMenuSystem.h"

namespace System {
	void PauseMenu::render() {
		LP_3DDEVICE device = graphics->get3Ddevice();
		device->Clear(0, NULL, D3DCLEAR_TARGET, graphicsNS::PAUSE_BACKGROUND_COLOR, 0.0f, 0);
	
	}

	void PauseMenu::update(float frametime) {
		Entity::createButtonEntity(this->manager, this->graphics, "Resume", GAME_WIDTH / 2, GAME_HEIGHT / 4,20);
		Entity::createButtonEntity(this->manager, this->graphics, "Back Menu", GAME_WIDTH / 2, GAME_HEIGHT / 3,20);
	}
}