#pragma once

#include <vector>
#include "manager.h"
#include "system.h"
#include "graphics.h"

namespace ECS {

class SystemRunner {
	private:
		std::vector<System*> systems;

	public:
		SystemRunner() {};
		~SystemRunner() {};

		std::vector<System*> getSystems() { return this->systems; };
		void registerSystem(System* system);

		void initialize(Manager* manager, Graphics* graphics);
		void update(float frameTime);
		void render();
		void releaseAll();
		void resetAll();
};

}
