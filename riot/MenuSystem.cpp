#include "MenuSystem.h"

namespace System {

	void MenuSystem::initialize(ECS::Manager* manager, Graphics* graphics, Input* input) {
		System::initialize(manager, graphics, input);

		std::ifstream map;
		map.open("map.txt");
		while (map)
		{
			std::string line;
			std::getline(map, line);
			std::wstring wLine = std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(line);
			level += wLine;
		}

		int playerX;
		int playerY;

		for (int y = 0; y < visibleY; y++)
		{
			for (int x = 0; x < visibleX; x++)
			{
				int count = (y * levelWidth) + x;
				switch (level[count]) {
				case L'#':
					Entity::createTileEntity(this->manager, this->graphics, x, y, 1);
					break;
				case L'@':
					Entity::createTileEntity(this->manager, this->graphics, x, y, 0);
					playerX = x;
					playerY = y;
					break;
				case L'=':
					Entity::createTileEntity(this->manager, this->graphics, x, y, 2);
					break;
				default:
					Entity::createTileEntity(this->manager, this->graphics, x, y, 0);
					break;
				}
			}
		}
		
		if (playerX && playerY)
		{
			Entity::createPlayerEntity(this->manager, this->graphics, playerX, playerY);
		}
	}

	void MenuSystem::releaseAll() {

	}
}