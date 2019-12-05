#pragma once
#include <vector>

#include "texture.h"
#include "system.h"
#include "manager.h"
#include <string>
#include "Entity.h"
#include "Button.h"

namespace System {

	class MainMenuSystem : public ECS::System {

	public:
		void render(ECS::Manager* manager);

	};

}