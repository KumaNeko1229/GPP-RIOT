#pragma once

#include "system.h"
#include "manager.h"
#include "Clickable.h"
#include "Button.h"

namespace System {

	class ClickSystem : public ECS::System {

	public:
		void update(float frametime);

	};

}
