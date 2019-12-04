#pragma once

#include "component.h"

namespace Component {

	struct Life : ECS::Component {
		float timeToLive = 0.0f;
	};

}
