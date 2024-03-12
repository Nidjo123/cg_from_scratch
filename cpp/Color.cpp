#include "Color.h"

Color::Color(uint8_t r, uint8_t g, uint8_t b): r_{r}, g_{g}, b_{b} {
}

uint8_t Color::r() const {
    return r_;
}

uint8_t Color::g() const {
    return g_;
}

uint8_t Color::b() const {
    return b_;
}
