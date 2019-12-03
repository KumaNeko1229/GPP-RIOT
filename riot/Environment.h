#pragma once
#include "entity.h"
#include "manager.h"
#include "texture.h"
#include "transform.h"
#include "graphics.h"
#include "constants.h"
#include <string>

namespace Entity {

	class Environment : ECS::Entity {
	private:
		std::wstring level;
		int levelWidth = 40;
		int levelHeight = 20;
		int tileHeight = 16;
		int tileWidth = 16;
		int visibleX = GAME_WIDTH/tileWidth;
		int visibleY = GAME_HEIGHT/tileHeight;
		int cameraX = 1.0f;
		int cameraY = 1.0f;
	public:
		Environment();
		virtual ~Environment();
		auto GetTile(float x, float y);
		auto SetTile(float x, float y, wchar_t newTile);
	};
}