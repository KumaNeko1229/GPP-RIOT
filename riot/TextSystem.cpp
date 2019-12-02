#include "TextSystem.h";

namespace System {

	void TextSystem::initialize(ECS::Manager* manager, Graphics* graphics) {
		/*if (font->initialize(graphics, 40, false, false, "Arial") == false)
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing DirectX font"));*/

	}

	void TextSystem::update(float frameTime) {}

	void TextSystem::render() {
		graphics->beginScene();

		/*this->manager->getComponents<Component::Text>();

		font->print(text, sprite->x, sprite->y);*/

		graphics->endScene();

	}

	void TextSystem::releaseAll() {
	}

	void TextSystem::resetAll() {
	}




}