#pragma once


#include "component.h"

namespace Component {

	struct Physics : ECS::Component {
		float velocity = 0.0f;
		float acceleration = 0.0f;
	};

}