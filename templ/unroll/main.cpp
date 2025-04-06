// https://www.cppstories.com/2024/unroll-templates-lambdas-and-fold/

#include <array>
#include <cassert>
#include <iostream>
#include <utility>

// Helper to implement unroll via parameter pack expansion
template <class Fn, std::size_t... I>
void unroll_impl(Fn fn, std::index_sequence<I...>) {
  (fn(I), ...);  // Calls fn(0), fn(1), ..., fn(N-1)
}

// Primary unroll function
template <int N, class Fn>
void unroll(Fn fn) {
  unroll_impl(fn, std::make_index_sequence<N>());
}

// Base vector structure with 4 components
template <typename T>
struct Vector4 {
  T x, y, z, w;

  // Element access using indices
  T& operator[](int index) {
    assert(index >= 0 && index < 4);
    return reinterpret_cast<T*>(this)[index];
  }

  const T& operator[](int index) const {
    assert(index >= 0 && index < 4);
    return reinterpret_cast<const T*>(this)[index];
  }

  // Vector addition using unroll and lambda
  Vector4 operator+(const Vector4& other) const {
    Vector4 result;
    unroll<4>([&](auto i) { result[i] = (*this)[i] + other[i]; });
    return result;
  }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector4<T>& v) {
  unroll<4>([&](auto i) { os << v[i] << " "; });
  return os;
}

int main() {
  Vector4<float> vec1 = {1.0f, 2.0f, 3.0f, 4.0f};
  Vector4<float> vec2 = {5.0f, 6.0f, 7.0f, 8.0f};

  Vector4<float> sum = vec1 + vec2;

  std::cout << "Sum: " << sum;

  return 0;
}
