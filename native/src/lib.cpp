#include "lib.hpp"

#include <SDL2/SDL.h>

#include <cstdio>
#include <iostream>

void Print() { std::cout << "Hello from C++" << std::endl; }

#ifdef _WIN32
    #define FUNC_SIG __FUNCSIG__
#else
    #define FUNC_SIG __PRETTY_FUNCTION__
#endif

#define CHECK_SDL_ERROR()                                                    \
    {                                                                        \
        auto err = SDL_GetError();                                           \
        if (err != nullptr && strlen(err) != 0) {                            \
            std::fprintf(stdout,                                             \
                         "SDL error occurred at %s:%d in function %s: %s\n", \
                         __FILE__, __LINE__, FUNC_SIG, err);                 \
            SDL_ClearError();                                                \
            abort();                                                         \
        }                                                                    \
    }

class MyWindow {
   public:
    MyWindow() {
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

        SDL_SetRenderDrawColor(m_Renderer, 255, 0, 0, 255);
        CHECK_SDL_ERROR();

        SDL_Delay(100);

        SDL_RenderClear(m_Renderer);
        CHECK_SDL_ERROR();

        SDL_RenderPresent(m_Renderer);
        CHECK_SDL_ERROR();
    }

    ~MyWindow() {
        SDL_DestroyRenderer(m_Renderer);
        SDL_DestroyWindow(m_Window);
        SDL_Quit();
    }

   private:
    SDL_Window* m_Window;
    SDL_Renderer* m_Renderer;
};

static MyWindow* WindowInstance = nullptr;

void MakeWindow() {
    if (WindowInstance) return;

    WindowInstance = new MyWindow();
}

void CloseWindow() {
    if (!WindowInstance) return;

    delete WindowInstance;
    // WindowInstance = nullptr;
}