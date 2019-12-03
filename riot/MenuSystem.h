#pragma once
#include <vector>

#include "texture.h"
#include "system.h"
#include "manager.h"

namespace System {

	class MenuSystem : ECS::System {

	public:
		void initialize(ECS::Manager* manager);

	};

}