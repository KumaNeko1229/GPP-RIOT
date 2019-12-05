#pragma once

#include "Component.h"

namespace Component {

struct Position : ECS::Component {
	float x = 0;
	float y = 0;
};

}
