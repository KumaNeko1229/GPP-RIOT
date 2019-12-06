#pragma once

#include "Component.h"
#include "textDX.h"
#include <string>

namespace Component {

	struct Text : ECS::Component {
		std::string text;
		TextDX *font;
		int fontsize;
		int fontx;
		int fonty;
	};

}
