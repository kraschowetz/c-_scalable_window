#include "Engine.hpp"
#include "../graphics/Canvas.hpp"
#include "Input.hpp"
#include "Timer.hpp"


void Engine::start() {
	running = true;

	g_canvas->setScale();
	g_canvas->updateCanvasSpace();
	
	run();
}

void Engine::stop() {
	g_canvas.reset();

	running = false;
}

void Engine::run() {
	Timer deltaTimer;
	deltaTimer.start();

	while(running) {
		pollEvents();
		update(deltaTime);
		deltaTime = static_cast<double>(deltaTimer.getTicks() / 1000.f);
		deltaTimer.start();
		g_canvas->render();
	}

	stop();
}

void Engine::pollEvents() {
	SDL_Event e;
	SDL_PollEvent(&e);

	g_input.pollEvents(e);

	switch(e.type) {
		case SDL_QUIT:
			running = false;
			break;
	}
	switch(e.window.event) {
		case SDL_WINDOWEVENT_SIZE_CHANGED:
			SDL_GetWindowSize(
				g_canvas->getWindow(),
				&g_canvas->width,
				&g_canvas->height	
			);
			g_canvas->setScale();
			g_canvas->updateCanvasSpace();	
	}
}

void Engine::update(double delta) {
	if(g_input.getKeyJustPressed(ANY_KEY)) {
		stop();
	}
	g_input.update();
}
