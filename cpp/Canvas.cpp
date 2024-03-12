#include "Canvas.h"

Canvas::Canvas(int width, int height): width_{width}, height_{height}, pixels_(width * height) {
}

void Canvas::PutPixel(int x, int y, const Color& color) {
    pixels_[y * width_ + x] = color;
}

const Color& Canvas::GetPixel(int x, int y) const {
    return (*this)[y * width_ + x];
}

const Color& Canvas::operator[](size_t idx) const {
    return pixels_[idx];
}

int Canvas::width() const {
    return width_;
}

int Canvas::height() const {
    return height_;
}
