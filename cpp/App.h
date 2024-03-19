#ifndef APP_H
#define APP_H

#include <string>

#include <SDL.h>

#include "Canvas.h"

class App {
public:
    explicit App(std::string name, int width, int height);

    virtual ~App();

    virtual void Render();

    void Run();

private:
    void UpdateScreen();

protected:
    Canvas canvas_;

private:
    SDL_Window* window_{};
};


#endif //APP_H
