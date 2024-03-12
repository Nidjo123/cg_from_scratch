#ifndef COLOR_H
#define COLOR_H

#include <cstdint>

class Color {
public:
    Color() = default;

    Color(uint8_t r, uint8_t g, uint8_t b);

    uint8_t r() const;

    uint8_t g() const;

    uint8_t b() const;

private:
    uint8_t r_{}, g_{}, b_{};
};


#endif //COLOR_H
