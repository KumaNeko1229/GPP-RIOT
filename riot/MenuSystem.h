#pragma once
#include <vector>

#include "texture.h"
#include "system.h"
#include "manager.h"
#include <string>
#include "Entity.h"
#include "Tile.h"

namespace System {

	class MenuSystem : public ECS::System {
	private:
		std::wstring level;
	public:
		void initialize(ECS::Manager* manager);

	};

}