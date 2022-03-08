#pragma once

#include <SDL2/SDL.h>
#include <stdint.h>

class MyWindow {
   public:
    MyWindow();
    ~MyWindow();

    void Clear(uint8_t r, uint8_t g, uint8_t b);

   private:
    SDL_Window* m_Window{nullptr};
    SDL_Renderer* m_Renderer{nullptr};
};