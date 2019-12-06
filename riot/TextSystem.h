#pragma once

#include <string>

#include "System.h"
#include "Manager.h"
#include "textDX.h"
#include "ButtonEntity.h"
#include "TextureComponent.h"
#include "TextComponent.h"
#include "PositionComponent.h"

namespace System {

	class TextSystem : public ECS::System {

	public:
		void initialize(ECS::Manager* manager, Graphics* graphics);

		void update(float frameTime);

		void render();

		void releaseAll();

		void resetAll();
	};

}
