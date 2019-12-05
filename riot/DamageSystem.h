#pragma once

#include <vector>

#include "System.h"
#include "Manager.h"
#include "DamageComponent.h"
#include "BlockerEntity.h"
#include "EliteGuardEntity.h"
#include "EliteSoldierEntity.h"

namespace System {

	class Damage : public ECS::System {
	public:
		void update();
	};

}