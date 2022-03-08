#include "lib.hpp"

#include <SDL2/SDL.h>

#include <cstdio>
#include <iostream>

#include "MyWindow.hpp"

MyWindow* MakeWindow() { return new MyWindow(); }
void CloseWindow(MyWindow* window) { delete window; }
void Clear(MyWindow* window, uint8_t r, uint8_t g, uint8_t b) {
    window->Clear(r, g, b);
}
