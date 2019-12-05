#include "GameStateComponent.h"

namespace Component {
	int GameState::getWidth() {
		return this->renderRect.right - this->renderRect.left;
	}

	int GameState::getHeight() {
		return this->renderRect.bottom - this->renderRect.top;
	}
}