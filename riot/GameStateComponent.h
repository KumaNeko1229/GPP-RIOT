#pragma once

#include <d3d9.h>
#include "Component.h"

namespace Component {

	struct GameState : ECS::Component {
		RECT renderRect;

		int getWidth();
		int getHeight();
	};

}
