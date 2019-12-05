#include "MenuSystem.h"

namespace System {

	void Menu::initialize(ECS::Manager* manager, Graphics* graphics, Input* input) {
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

		std::vector<std::vector<int>> enemy;

		for (int y = 0; y < visibleY; y++)
		{
			for (int x = 0; x < visibleX; x++)
			{
				int count = (y * levelWidth) + x;
				switch (level[count]) {
				case L'#':
					Entity::createWallEntity(this->manager, this->graphics, x, y);
					break;
				case L'@':
					Entity::createTileEntity(this->manager, this->graphics, x, y);
					playerX = x;
					playerY = y;
					break;
				case L'=':
					Entity::createHalfwallEntity(this->manager, this->graphics, x, y);
					break;
				case L'b':
					Entity::createTileEntity(this->manager, this->graphics, x, y);
					enemy.push_back({ 1, x, y });
					break;
				case L'g':
					Entity::createTileEntity(this->manager, this->graphics, x, y);
					enemy.push_back({ 2, x, y });
					break;
				case L'G':
					Entity::createTileEntity(this->manager, this->graphics, x, y);
					enemy.push_back({ 3, x, y });
					break;
				case L'S':
					Entity::createTileEntity(this->manager, this->graphics, x, y);
					enemy.push_back({ 4, x, y });
					break;
				default:
					Entity::createTileEntity(this->manager, this->graphics, x, y);
					break;
				}
			}
		}

		if (playerX && playerY)
		{
			Entity::createPlayerEntity(this->manager, this->graphics, playerX, playerY);
		}

		for (int  i = 0; i < enemy.size(); i++)
		{
			switch (enemy[i][0]) {
			case 1:
				Entity::createBlockerEntity(this->manager, this->graphics, enemy[i][1], enemy[i][2]);
				break;
			case 2:
				Entity::createGuardEntity(this->manager, this->graphics, enemy[i][1], enemy[i][2]);
				break;
			case 3:
				Entity::createEliteGuardEntity(this->manager, this->graphics, enemy[i][1], enemy[i][2]);
				break;
			case 4:
				Entity::createEliteSoldierEntity(this->manager, this->graphics, enemy[i][1], enemy[i][2]);
				break;
			}
		}
	}

	void Menu::releaseAll() {

	}
}