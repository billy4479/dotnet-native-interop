#pragma once

// Taken from https://gcc.gnu.org/wiki/Visibility but adapted by me

#if defined _WIN32 || defined __CYGWIN__
    #ifdef __GNUC__
        #define DLL_PUBLIC __attribute__((dllexport))
    #else
    // Note: actually gcc seems to also supports this syntax.
        #define DLL_PUBLIC __declspec(dllexport)
    #endif
    #define DLL_LOCAL
#else
    #define DLL_PUBLIC __attribute__((visibility("default")))
    #define DLL_LOCAL __attribute__((visibility("hidden")))
#endif
