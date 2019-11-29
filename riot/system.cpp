#include "system.h"

namespace ECS {

System::System() {}

System::~System() {
	this->manager = NULL;
	this->graphics = NULL;
}

void System::initialize(Manager* manager, Graphics* graphics) {
	this->manager = manager;
	this->graphics = graphics;
}

}