#pragma once

#include "component.h"

namespace Component {

	struct Attack : ECS::Component {
		float cooldownTime = 0.0f;
		float interval = 0.0f;
		float attackDelay = 0.0f;
		float range = 0.0f;
	};

}
