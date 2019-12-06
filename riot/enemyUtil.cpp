#include "enemyUtil.h"

bool withinRange(float a, float b, float value)
{
	if (a < b)
	{
		return (a < value) && (value < b);
	}
	else
	{
		return (b < value) && (value < a);
	}
}

bool inLineOfSight(
	Component::Position playerPos,
	Component::Position enemyPos,
	std::forward_list<Component::Collidable> walls
)
{
	// Calculate the gradient between the enemy and player
	float gradient = (playerPos.y - enemyPos.y) / (playerPos.x - enemyPos.x);
	for (Component::Collidable& wall : walls)
	{
		std::vector<D3DXVECTOR2> sortedCorners = wall.getSortedCorners();

		// Check if wall is between the player and the enemy position
		bool isBetween = false;
		for (D3DXVECTOR2 corner : sortedCorners)
		{
			if (withinRange(playerPos.x, enemyPos.x, corner.x))
			{
				isBetween = true;
				break;
			}

			if (withinRange(playerPos.y, enemyPos.y, corner.y))
			{
				isBetween = true;
				break;
			}
		}

		if (!isBetween)
		{
			continue;
		}

		D3DXVECTOR2& bottomLeftCorner = sortedCorners[3];
		D3DXVECTOR2& topRightCorner = sortedCorners[1];

		// Check using bottom left corner
		float y = gradient * (bottomLeftCorner.x - playerPos.x) + playerPos.y;
		float x = (bottomLeftCorner.y - playerPos.y) / gradient + playerPos.x;

		// Check if the x intersects the bottom of the wall
		if (sortedCorners[3].x <= x && x <= sortedCorners[2].x)
		{
			return false;
		}

		// Check if the y intersects the left of the wall
		if (gradient < INFINITY && sortedCorners[0].y <= y && y <= sortedCorners[3].y)
		{
			return false;
		}

		// Calculate the new x for the right of the wall
		y = gradient * (topRightCorner.x - playerPos.x) + playerPos.y;
		if (gradient < INFINITY && sortedCorners[1].y < y && y < sortedCorners[2].y)
		{
			return false;
		}
	}

	return true;
}

bool checkForRange(float range, Component::Position playerPos, Component::Position enemyPos)
{
	// squaring the values ensure a positive number, and allows distance comparison without use of square root
	if (pow(range, 2) - pow(playerPos.x - enemyPos.x, 2) - pow(playerPos.y - enemyPos.y, 2))
		return true;
	else
		return false;
}
