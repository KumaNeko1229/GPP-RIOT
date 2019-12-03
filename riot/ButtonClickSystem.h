#pragma once

#include "system.h"
#include "manager.h"

namespace System {

	class ButtonClickSystem : public ECS::System {
	public:
		void initialize(ECS::Manager* manager);

	};

}
