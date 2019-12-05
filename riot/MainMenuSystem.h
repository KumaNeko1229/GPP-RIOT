#pragma once

#include <vector>
#include <string>

#include "Entity.h"
#include "System.h"
#include "Manager.h"
#include "ButtonEntity.h"
#include "TextureComponent.h"

namespace System {

	class MainMenu : public ECS::System {

	public:
		void render(ECS::Manager* manager);

	};

}