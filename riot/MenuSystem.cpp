#include "MenuSystem.h"

namespace System {

	void MenuSystem::initialize(ECS::Manager* manager, Graphics* graphics, Input* input) {
		System::initialize(manager, graphics, input);
		level += L"........#..##################......#.............";
		level += L"........#...................#......#.............";
		level += L"........#..#................#......############..";
		level += L"...@....#..#................#.................#..";
		level += L"...........#..#################..###..........#..";
		level += L"........#..#.......................#..........#..";
		level += L"........#..#=======..========..##..############..";
		level += L"#########..#................=..##................";
		level += L"...........#................=..##....############";
		level += L"..##########................=..##....#...........";
		level += L"..#........#=================..##.....#..........";
		level += L"..#............................##......#.....#...";
		level += L"..#........#......##########...##.......#....#...";
		level += L"..#....#####......#........#...##........#####...";
		level += L"..#....#..........#........#...##................";
		level += L".......#...#..#####............##......##########";
		level += L"..#....#...#......#....#####...##.....#..........";
		level += L"..#....#...#......#....#.......##....#...........";
		level += L"..######...#......#....#.......##...##########...";
		level += L"...........#......#....#.........................";

		int playerX;
		int playerY;

		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 49; x++)
			{
				int count = (y * 49) + x;
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