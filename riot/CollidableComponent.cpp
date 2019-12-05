#include "CollidableComponent.h"

namespace Component {

	D3DXVECTOR2 Collidable::getCenter() {
		D3DXVECTOR2 centerVector {0, 0};
		for (D3DXVECTOR2 cornerVector : this->corners)
		{
			centerVector += cornerVector;
		}

		centerVector /= this->corners.size();

		return centerVector;
	}

	std::vector<D3DXVECTOR2> Collidable::getSortedCorners() {
		// Find the difference for each vector and the center vector
		D3DXVECTOR2 centerVector = this->getCenter();

		std::vector<D3DXVECTOR2> differenceVectors;
		differenceVectors.reserve(this->corners.size());
		std::vector<size_t> differenceVectorsIndices;
		differenceVectorsIndices.reserve(this->corners.size());

		for (size_t i = 0; i < this->corners.size(); i++)
		{
			differenceVectors.push_back(this->corners[i] - centerVector);
			differenceVectorsIndices.push_back(i);
		}

		// Sort the vectors clockwise
		std::sort(
			differenceVectorsIndices.begin(),
			differenceVectorsIndices.end(),
			[&differenceVectors](size_t a, size_t b) {
				// Compare the angles from the x axis
				D3DXVECTOR2& vectorA = differenceVectors[a];
				D3DXVECTOR2& vectorB = differenceVectors[b];

				float aAngle = atan(vectorA.y / vectorA.x);
				float bAngle = atan(vectorB.y / vectorB.x);
				return aAngle < bAngle;
			}
		);

		// Find the top left corner
		float shortestDistance = INFINITY;
		size_t topRightVectorIndex = 0;
		for (size_t index : differenceVectorsIndices)
		{
			D3DXVECTOR2& vector = differenceVectors[index];
			float footOfPerpendicularX = (vector.y - vector.x)/2.0f;
			float footOfPerpendicularY = -footOfPerpendicularX;

			float xDiff = footOfPerpendicularX - vector.x;
			xDiff *= xDiff;
			float yDiff = footOfPerpendicularY - vector.y;
			yDiff *= yDiff;

			float squaredDistance = xDiff + yDiff;

			if (squaredDistance <= shortestDistance)
			{
				shortestDistance = squaredDistance;
			}
			else
			{
				// Since it is already sorted, we do not need to check further
				topRightVectorIndex = index - 1;
				break;
			}
		}

		// Create the sorted corners
		std::vector<D3DXVECTOR2> sortedCorners;
		sortedCorners.reserve(this->corners.size());
		for (size_t i = 0; i < this->corners.size(); i++)
		{
			// Start from top right vector index and wrap around
			size_t index = topRightVectorIndex + i;
			if (index >= this->corners.size())
			{
				index -= this->corners.size();
			}

			sortedCorners[i] = this->corners[index];
		}

		return sortedCorners;
	}
}