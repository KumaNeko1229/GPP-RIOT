#pragma once
#include <vector>

#include "texture.h"
#include "system.h"
#include "manager.h"
#include <string>

namespace System {

	class MenuSystem : ECS::System {
	private:
		std::wstring level;
	public:
		void initialize(ECS::Manager* manager);

	};

}