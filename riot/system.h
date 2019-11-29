#pragma once

#include "manager.h"
#include "graphics.h"

namespace ECS {

class System {
	protected:
		Manager* manager = NULL;
		Graphics* graphics = NULL;

	public:
		System();
		~System();

		virtual void initialize(Manager* manager, Graphics* graphics);

		virtual void update(float frameTime) = 0;

		virtual void render() = 0;

		virtual void releaseAll() = 0;

		virtual void resetAll() = 0;
};

}
