#pragma once

#include "manager.h"
#include "graphics.h"

namespace ECS {

class System {
	public:
		System() {};
		~System() {};

		virtual void initialize(Manager* manager, Graphics* graphics) = 0;

		virtual void update(Manager* manager) = 0;

		virtual void render(Manager* manager) = 0;

		virtual void releaseAll(Manager* manager) = 0;

		virtual void resetAll(Manager* manager) = 0;
};

}
