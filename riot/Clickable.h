#pragma once

#include "Component.h"
#include "Manager.h"

namespace Component {

	struct Clickable : ECS::Component {
		bool click = false;
		void isClickable(ECS::Manager* manager);
	};
}