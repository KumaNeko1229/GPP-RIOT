#include "texture.h"

namespace Component {

bool Texture::loadTexture(Graphics* graphics, std::string filePath) {
	this->filePath = filePath;

	try
	{
		HRESULT hr = graphics->loadTexture(
			filePath.c_str,
			TRANSCOLOR,
			this->totalWidth,
			this->totalHeight,
			this->texture
		);

		if (FAILED(hr))
		{
			SAFE_RELEASE(this->texture);
			return false;
		}

		return true;
	}
	catch (...)
	{
		return false;
	}
}

}