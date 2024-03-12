#include <iostream>

#include "App.h"


static void InitSDL() {
    if (SDL_Init(SDL_INIT_VIDEO)) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Failed to initialize SDL: %s", SDL_GetError());
        throw std::runtime_error{"Failed to initialize SDL"};
    }
}

App::App(std::string name, int width, int height) : canvas_{width, height} {
    InitSDL();
    window_ = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height,
                               SDL_WINDOW_SHOWN);
    if (!window_) {
        SDL_LogError(SDL_LOG_CATEGORY_VIDEO, "Failed to create window: %s", SDL_GetError());
    }
}

App::~App() {
    if (window_) {
        SDL_DestroyWindow(window_);
    }
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
    SDL_Quit();
}

void App::Render() {
    auto window_surface = SDL_GetWindowSurface(window_);
#ifdef SDL_MUSTLOCK
    SDL_LockSurface(window_surface);
#endif
    for (auto y = 0; y < canvas_.height(); y++) {
        for (auto x = 0; x < canvas_.width(); x++) {
            auto pixel = (Uint32 *) (static_cast<uint8_t *>(window_surface->pixels) + y * window_surface->
                                     pitch + x * window_surface->format->BytesPerPixel);
            const auto color = canvas_.GetPixel(x, y);
            *pixel = SDL_MapRGB(window_surface->format, color.r(), color.g(), color.b());
        }
    }

#ifdef SDL_MUSTLOCK
    SDL_UnlockSurface(window_surface);
#endif

    SDL_UpdateWindowSurface(window_);
}

void App::Run() {
    bool running = true;

    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
            }
        }
        for (auto x = 0; x < 100; x++)
            canvas_.PutPixel(x, 50, Color{255, 255, 255});
        Render();
    }
}
