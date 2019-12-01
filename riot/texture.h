#pragma once

#include <d3d9.h>
#include <string>
#include "component.h"
#include "graphics.h"
#define LP_TEXTURE LPDIRECT3DTEXTURE9

namespace Component {

struct Texture : ECS::Component {
	bool visible;

	UINT totalWidth;
	UINT totalHeight;

	RECT viewableRect;

	std::string filePath;
	LP_TEXTURE texture;
	COLOR_ARGB filter = graphicsNS::WHITE;

	bool loadTexture(Graphics* graphics, const char* filePath);
};

}
