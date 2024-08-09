#pragma once

#include <SDL.h>
#include <vector>

#define ANY_KEY -1

class InputHandler {
    private:
        std::vector<int> keysPressed;
        std::vector<int> keysJustPressed;
        std::vector<int> keysJustReleased;
    public:
        void update();
        void pollEvents(SDL_Event e);
    public:
        bool getKeyPressed(int k);
        bool getKeyJustPressed(int k);
        bool getKeyJustReleased(int k);
};

extern InputHandler g_input;
