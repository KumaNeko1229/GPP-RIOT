#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <codecvt>
#include <list>

#include "System.h"
#include "Manager.h"
#include "Entity.h"
#include "TileEntity.h"
#include "WallEntity.h"
#include "HalfwallEntity.h"
#include "PlayerEntity.h"
#include "GuardEntity.h"
#include "BlockerEntity.h"
#include "EliteGuardEntity.h"
#include "EliteSoldierEntity.h"
#include "TextureComponent.h"

namespace System {

	class Menu : public ECS::System {
	private:
		std::wstring level;
	public:
		void initialize(ECS::Manager* manager, Graphics* graphics, Input* input);
		void releaseAll();

	};

}