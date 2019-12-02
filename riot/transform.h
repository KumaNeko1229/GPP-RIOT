#pragma once

#include "component.h"

namespace Component {

struct Transform : ECS::Component {
	int width = 0;
	int height = 0;
	float scale = 1;
	float angle = 0;
	bool flipHorizontal = false;
	bool flipVertical = false;
};

}
