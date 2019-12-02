#pragma once

#include "component.h"
#include "manager.h"

namespace Component {

	struct Collidable : ECS::Component {
		int collideWith[5] = {};

		void onEnter(ECS::Manager* manager, int id);

		void onStay(ECS::Manager* manager, int id);

		void onExit(ECS::Manager* manager, int id);
	};

}

