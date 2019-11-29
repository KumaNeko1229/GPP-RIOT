#include "systemRunner.h"

namespace ECS {

void SystemRunner::setManager(Manager* manager) {
	this->manager = manager;
}

void SystemRunner::registerSystem(System* system) {
	this->systems.push_back(system);
}

void SystemRunner::initialize(Graphics* graphics) {
	for (ECS::System* systemPtr : this->getSystems()) {
		systemPtr->initialize(this->manager, graphics);
	}
}

void SystemRunner::update() {
	for (ECS::System* systemPtr : this->getSystems()) {
		systemPtr->update(this->manager);
	}
}

void SystemRunner::render() {
	for (ECS::System* systemPtr : this->getSystems()) {
		systemPtr->render(this->manager);
	}
}

void SystemRunner::releaseAll() {
	for (ECS::System* systemPtr : this->getSystems()) {
		systemPtr->releaseAll(this->manager);
	}

	// Release manager as well
	SAFE_DELETE(this->manager);
}

void SystemRunner::resetAll() {
	for (ECS::System* systemPtr : this->getSystems()) {
		systemPtr->resetAll(this->manager);
	}
}

}
