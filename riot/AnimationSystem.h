#pragma once

#include <vector>

#include "System.h"
#include "Manager.h"
#include "Animatable.h"
#include "Texture.h"

namespace System {

	class AnimationSystem: public ECS::System {
		public:
			void update(float frameTime);
	};

}