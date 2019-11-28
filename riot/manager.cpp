#include "manager.h"

namespace ECS {

void Manager::registerSystem(System* system) {
	this->systems.push_back(system);
}

}
