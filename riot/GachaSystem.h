#pragma once

#include <vector>

#include "System.h"
#include "Manager.h"
#include "PlayerEntity.h"
#include "ButtonEntity.h"
#include "DamageComponent.h"
#include "GachaEntity.h"

namespace System {

	class Gacha : public ECS::System {
	public:
		void update();
	};

}
