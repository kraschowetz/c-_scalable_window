#include "Canvas.hpp"

#include <iostream>
#include <memory>

std::unique_ptr<Canvas>g_canvas = std::make_unique<Canvas>();

Canvas::Canvas() {
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) { 
		std::cerr << "SDL ERROR: " << SDL_GetError();
	}

	this->window = SDL_CreateWindow(
		"podxada sinicast",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		this->width,
		this->height,
		SDL_WINDOW_RESIZABLE
	);

	if(!this->window) {
		std::cerr << "SDL ERROR: " << SDL_GetError();
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

	this->renderer = SDL_CreateRenderer(
		this->window,
		-1,
		SDL_RENDERER_ACCELERATED
	);

	if(!this->renderer) {
		std::cerr << "SDL ERROR: " << SDL_GetError();
	}

	SDL_SetRenderDrawBlendMode(this->renderer, SDL_BLENDMODE_BLEND);
}

Canvas::~Canvas() {
	SDL_DestroyWindow(this->window);
	SDL_DestroyRenderer(this->renderer);

	this->window = nullptr;
	this->renderer = nullptr;
}

void Canvas::render() {
	SDL_RenderClear(this->renderer);

	SDL_SetRenderDrawColor(
		this->renderer,
		64,
		64,
		64,
		255
	);

	SDL_RenderFillRect(
		this->renderer,
		&this->canvasSpace
	);

	SDL_SetRenderDrawColor(
		this->renderer,
		0,
		0,
		0,
		255
	);
SDL_RenderPresent(this->renderer); }
void Canvas::setScale() {
	float h_scale = static_cast<float>(width) / ASPECT_RATIO[0];
	float v_scale = static_cast<float>(height) / ASPECT_RATIO[1];

	scale = h_scale < v_scale? h_scale : v_scale;
}

void Canvas::updateCanvasSpace() {
	canvasSpace.x = static_cast<int>((width - (ASPECT_RATIO[0] * scale)) / 2);
	canvasSpace.y = static_cast<int>((height - (ASPECT_RATIO[1] * scale)) / 2);
	canvasSpace.w = ASPECT_RATIO[0] * scale;
	canvasSpace.h = ASPECT_RATIO[1] * scale;
}
