#pragma once

#include <vector>
#include <string>

#include "System.h"
#include "Manager.h"
#include "Entity.h"
#include "PauseEntity.h"
#include "ButtonEntity.h"
#include "TextureComponent.h"
#include "GameStateComponent.h"

namespace System {

	class PauseMenu : public ECS::System {

	public:
		void render();
		void update(float frametime);

	};

}