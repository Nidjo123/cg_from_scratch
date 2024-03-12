#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include "Color.h"


class Canvas {
public:
    explicit Canvas(int width, int height);

    ~Canvas() = default;

    void PutPixel(int x, int y, const Color& color);

    const Color& GetPixel(int x, int y) const;
    const Color& operator[](size_t idx) const;

    int width() const;

    int height() const;

private:
    int width_{};
    int height_{};
    std::vector<Color> pixels_;
};


#endif //CANVAS_H
