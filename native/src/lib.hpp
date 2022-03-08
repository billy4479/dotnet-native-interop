#pragma once

#include <stdint.h>

#include "Visibility.hpp"

#ifdef __cplusplus
extern "C" {
#endif

class MyWindow;

DLL_PUBLIC MyWindow* MakeWindow();
DLL_PUBLIC void CloseWindow(MyWindow*);
DLL_PUBLIC void Clear(MyWindow*, uint8_t r, uint8_t g, uint8_t b);

#ifdef __cplusplus
}
#endif