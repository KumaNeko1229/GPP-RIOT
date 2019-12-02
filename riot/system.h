#pragma once

#include "manager.h"
#include "graphics.h"
#include "input.h"

namespace ECS {

class System {
	protected:
		Manager* manager = NULL;
		Graphics* graphics = NULL;
		Input* input = NULL;

	public:
		System();
		~System();

		virtual void initialize(Manager* manager, Graphics* graphics, Input* input);

		virtual void update(float frameTime) = 0;
};

}
