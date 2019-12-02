#include "SystemRunner.h"

namespace ECS {

void SystemRunner::registerSystem(System* system) {
	this->systems.push_back(system);
}

void SystemRunner::initialize(Manager* manager, Graphics* graphics, Input* input) {
	for (ECS::System* systemPtr : this->getSystems()) {
		systemPtr->initialize(manager, graphics, input);
	}
}

void SystemRunner::update(float frameTime) {
	for (ECS::System* systemPtr : this->getSystems()) {
		systemPtr->update(frameTime);
	}
}

void SystemRunner::render() {
	for (ECS::System* systemPtr : this->getSystems()) {
		systemPtr->render();
	}
}

void SystemRunner::releaseAll() {
	for (ECS::System* systemPtr : this->getSystems()) {
		systemPtr->releaseAll();
	}
}

void SystemRunner::resetAll() {
	for (ECS::System* systemPtr : this->getSystems()) {
		systemPtr->resetAll();
	}
}

}
