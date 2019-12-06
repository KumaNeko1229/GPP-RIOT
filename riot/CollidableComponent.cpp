#include "CollidableComponent.h"

namespace Component {
	float getPolarAngle(D3DXVECTOR2& vector) {
		float basicAngle = abs(atan(vector.y / vector.x));
		if (vector.x > 0 && vector.y > 0)
		{
			// First quadrant
			return basicAngle;
		}
		else if (vector.x <= 0 && vector.y > 0)
		{
			// Second quadrant
			return PI - basicAngle;
		}
		else if (vector.x <= 0 && vector.y <= 0)
		{
			// Third quadrant
			return -(PI - basicAngle);
		}
		else
		{
			// Fourth quadrant
			return -basicAngle;
		}
	}

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
			D3DXVECTOR2 differenceVector = this->corners[i] - centerVector;
			// Flip the y axis because y increases downwards
			differenceVector.y = -differenceVector.y;
			differenceVectors.push_back(differenceVector);
			differenceVectorsIndices.push_back(i);
		}

		// Sort the vectors clockwise
		std::sort(
			differenceVectorsIndices.begin(),
			differenceVectorsIndices.end(),
			[&differenceVectors](size_t a, size_t b) {
				D3DXVECTOR2& vectorA = differenceVectors[a];
				D3DXVECTOR2& vectorB = differenceVectors[b];

				// Compare the angles from the x axis
				float aAngle = getPolarAngle(vectorA);
				float bAngle = getPolarAngle(vectorB);
				return getPolarAngle(vectorA) > getPolarAngle(vectorB);
			}
		);

		// Find the top left corner
		float shortestDistance = INFINITY;
		size_t topLeftVectorIndex = 0;
		for (size_t i = 0; i < differenceVectorsIndices.size(); i++)
		{
			size_t index = differenceVectorsIndices[i];
			D3DXVECTOR2& vector = differenceVectors[index];
			float footOfPerpendicularX = (vector.x - vector.y)/2.0f;
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
				topLeftVectorIndex = i - 1;
				break;
			}
		}

		// Create the sorted corners
		std::vector<D3DXVECTOR2> sortedCorners;
		sortedCorners.reserve(this->corners.size());
		sortedCorners.resize(this->corners.size());
		for (size_t i = 0; i < this->corners.size(); i++)
		{
			// Start from top right vector index and wrap around
			size_t index = topLeftVectorIndex + i;
			if (index >= this->corners.size())
			{
				index -= this->corners.size();
			}

			sortedCorners[i] = this->corners[differenceVectorsIndices[index]];
		}

		return sortedCorners;
	}
}