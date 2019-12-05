#pragma once

#include <vector>

#include "System.h"
#include "Manager.h"
#include "AnimatableComponent.h"
#include "TextureComponent.h"

namespace System {

	class Animation: public ECS::System {
		public:
			void update(float frameTime);
	};

}