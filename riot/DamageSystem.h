#pragma once

#include <vector>

#include "system.h"
#include "manager.h"
#include "Damage.h"
#include "Blocker.h"
#include "EliteGuard.h"
#include "EliteSoldier.h"

namespace System {

	class DamageSystem : public ECS::System {
	public:
		void update();
	};

}