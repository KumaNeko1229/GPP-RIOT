#pragma once

#include "Component.h"

namespace Component {

	struct Damage : ECS::Component {
		int health = 0;
		int damage = 0;
		int projectileDistanceLeft = 0;
		int reductionCounter = 0;
		bool revive = false;
	};

}
