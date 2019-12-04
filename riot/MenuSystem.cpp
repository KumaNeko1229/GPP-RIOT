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
					Entity::createPlayerEntity(this->manager, this->graphics);
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
	}

	void MenuSystem::releaseAll() {

	}
}