#include "MyWindow.hpp"

#include <iostream>

#include "Utils.hpp"

MyWindow::MyWindow() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Error init sdl\n";
    }
    CHECK_SDL_ERROR();

    m_Window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED, 1280, 720, 0);
    if (!m_Window) {
        std::cout << "Error create window\n";
    }
    CHECK_SDL_ERROR();

    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
    if (!m_Renderer) {
        std::cout << "Error create renderer\n";
    }
    CHECK_SDL_ERROR();

    SDL_Delay(100);

    Clear(0xff, 0, 0);
}

MyWindow::~MyWindow() {
    std::cout << "Closing" << std::endl;
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    SDL_Quit();
}

void MyWindow::Clear(uint8_t r, uint8_t g, uint8_t b) {
    SDL_SetRenderDrawColor(m_Renderer, r, g, b, 0xff);
    CHECK_SDL_ERROR();

    SDL_RenderClear(m_Renderer);
    CHECK_SDL_ERROR();

    SDL_RenderPresent(m_Renderer);
    CHECK_SDL_ERROR();
}