#pragma once

#include <vector>
#include <string>

#include "System.h"
#include "Manager.h"
#include "Entity.h"
#include "PauseEntity.h"
#include "ButtonEntity.h"
#include "TextureComponent.h"

namespace System {

	class PauseMenu : public ECS::System {

	public:
		void render(ECS::Manager* manager);

	};

}