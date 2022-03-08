#pragma once

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
