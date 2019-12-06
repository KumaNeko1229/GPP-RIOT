#include "PauseMenuSystem.h"

namespace System {

	void PauseMenu::update(ECS::Manager* manager) {

		D3DCOLOR windowColor = D3DCOLOR_XRGB(105, 105, 105);
		LP_3DDEVICE device = graphics->get3Ddevice();
		device->Clear(0, NULL, D3DCLEAR_TARGET, windowColor, 0.0f, 0);
		device->Present(NULL, NULL, NULL, NULL);

		Entity::createButtonEntity(this->manager, this->graphics, "Resume", GAME_WIDTH / 2, GAME_HEIGHT / 4,20);
		Entity::createButtonEntity(this->manager, this->graphics, "Back to Menu", GAME_WIDTH / 2, GAME_HEIGHT / 3,20);
	}
}