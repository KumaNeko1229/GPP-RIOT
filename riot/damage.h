#pragma once

#include "component.h"

namespace Component {

	struct Damage : ECS::Component {
		int health = 0;
		int damage = 0;
	};

}
