#pragma once

#include <vector>

#include "system.h"
#include "manager.h"
#include "Player.h"
#include "Damage.h"

namespace System {

	class GachaSystem : public ECS::System {
	public:
		void update();
	};

}
