#pragma once

#include "system.h"
#include "manager.h"
#include "Clickable.h"
#include "Button.h"
#include "Pause.h"

namespace System {

	class ClickSystem : public ECS::System {

	public:
		void update();

	};

}
