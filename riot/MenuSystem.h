#pragma once
#include <vector>

#include "texture.h"
#include "system.h"
#include "manager.h"
#include <string>
#include "Entity.h"
#include "Tile.h"
#include "Wall.h"
#include "Halfwall.h"
#include "Player.h"
#include "SystemRunner.h"
#include <fstream>
#include <codecvt>

namespace System {

	class MenuSystem : public ECS::System {
	private:
		std::wstring level;
	public:
		void initialize(ECS::Manager* manager, Graphics* graphics, Input* input);
		void releaseAll();

	};

}