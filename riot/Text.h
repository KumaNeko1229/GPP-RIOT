#pragma once

#include "component.h";
#include "textDX.h"
#include <string>

namespace Component {

	struct Text : ECS::Component {
		std::string text;
		TextDX* font;
	};

}
