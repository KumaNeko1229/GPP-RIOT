#pragma once

#include "component.h";
#include "manager.h";

namespace Component {

	struct Clickable : ECS::Component {

		void isClickable(ECS::Manager* manager);
	};
}