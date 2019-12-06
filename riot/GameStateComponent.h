#pragma once

#include <d3d9.h>
#include "Component.h"

namespace Component {

	enum class DisplayState {
		MENU,
		INGAME,
		PAUSED
	};

	struct GameState : ECS::Component {
		RECT renderRect;
		DisplayState displayState = DisplayState::MENU;

		int getWidth();
		int getHeight();
	};

}
