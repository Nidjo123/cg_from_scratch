#ifndef VECTOR_H
#define VECTOR_H

#include <algorithm>
#include <cstdlib>
#include <initializer_list>
#include <iostream>

template <typename T, const size_t N> class Vector {
public:
  Vector() = default;

  Vector(std::initializer_list<T> values) {
    std::copy(values.begin(), values.end(), values_);
  }

  Vector(const Vector &other) {
    std::copy(std::begin(other.values_), std::end(other.values_), values_);
  }

  const T &operator[](size_t idx) const { return values_[idx]; }
  T &operator[](size_t idx) { return values_[idx]; }

  Vector &operator*=(T factor) {
    for (auto i = 0; i < N; ++i) {
      values_[i] *= factor;
    }
    return *this;
  }

  Vector &operator/=(T factor) {
    *this *= 1.0 / factor;
    return *this;
  }

  Vector operator*(T factor) const {
    Vector res(*this);
    res *= factor;
    return res;
  }

  Vector operator/(T factor) const { return *this * (1.0 / factor); }

private:
  T values_[N] = {};
};

template <typename T, const size_t N>
std::ostream &operator<<(std::ostream &os, const Vector<T, N> &vector) {
  os << "(";
  for (auto i = 0; i < N; ++i) {
    os << vector[i];
    if (i < N - 1) {
      os << ", ";
    }
  }
  return os << ')';
}

using Vector2f = Vector<float, 2>;
using Vector2d = Vector<double, 2>;

using Vector3f = Vector<float, 3>;
using Vector3d = Vector<double, 3>;

#endif // VECTOR_H
