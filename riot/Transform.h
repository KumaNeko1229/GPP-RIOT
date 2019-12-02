#pragma once

#include "component.h"

namespace Component {

struct Transform : ECS::Component {
	float scale = 1;
	float angle = 0;
	bool flipHorizontal = false;
	bool flipVertical = false;
};

}
