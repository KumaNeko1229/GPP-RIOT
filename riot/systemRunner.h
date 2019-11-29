#pragma once

#include <vector>
#include "manager.h"
#include "system.h"
#include "graphics.h"

namespace ECS {

class SystemRunner {
	private:
		Manager* manager = NULL;
		std::vector<System*> systems;

	public:
		SystemRunner() {};
		~SystemRunner() {};

		void setManager(Manager* manager);

		std::vector<System*> getSystems() { return this->systems; };
		void registerSystem(System* system);

		void initialize(Graphics* graphics);
		void update();
		void render();
		void releaseAll();
		void resetAll();
};

}
