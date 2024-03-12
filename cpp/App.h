#ifndef APP_H
#define APP_H

#include <string>

#include <SDL.h>

#include "Canvas.h"

class App {
public:
    explicit App(std::string name, int width, int height);

    virtual ~App();

    void Render();

    void Run();

private:
    SDL_Window* window_{};
    Canvas canvas_;
};


#endif //APP_H
