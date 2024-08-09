#include "Input.hpp"

InputHandler g_input;

void InputHandler::pollEvents(SDL_Event e) {
	switch (e.type) {
		case SDL_KEYDOWN: {
			bool canInsert = true;
			for (int i : keysPressed) {
				if (i == e.key.keysym.sym) {
					canInsert = false;
				}
			}
			if (canInsert) {
				keysPressed.push_back(e.key.keysym.sym);
				keysJustPressed.push_back(e.key.keysym.sym);
			}
		}
		break;

		case SDL_KEYUP:
			for (int i = 0; i < keysPressed.size(); i++) {
				if (keysPressed.at(i) == e.key.keysym.sym) {
					keysJustReleased.push_back(e.key.keysym.sym);
					keysPressed.erase(keysPressed.begin() + i);
				}
			}
		break;
	}
}

void InputHandler::update() {
	if (!keysJustPressed.empty()) {
		keysJustPressed.clear();
	}
	if (!keysJustReleased.empty()) {
		keysJustReleased.clear();
	}
}

bool InputHandler::getKeyPressed(int k) {
	if(k != -1) {
		for (int i : keysPressed) {
			if (i == k) {
				return true;
			}
		}
		return false;
	}

	if(keysPressed.size() > 0) {
		return true;
	}
	return false;
}

bool InputHandler::getKeyJustPressed(int k) {
	if(k != -1) {
		for (int i : keysJustPressed) {
			if (i == k) {
				return true;
			}
		}
		return false;
	}

	if(keysJustPressed.size() > 0) {
		return true;
	}
	return false;
}

bool InputHandler::getKeyJustReleased(int k) {
	if(k != -1) {
		for (int i : keysJustReleased) {
			if (i == k) {
				return true;
			}
		}
		return false;
	}

	if(keysJustReleased.size() > 0) {
		return true;
	}
	return false;
}
