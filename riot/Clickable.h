#pragma once

#include "Component.h"
#include "Manager.h"

namespace Component {

	struct Clickable : ECS::Component {

		void isClickable(ECS::Manager* manager);
	};
}