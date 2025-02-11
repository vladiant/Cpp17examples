#include <iomanip>
#include <iostream>
#include <string>
#include <type_traits>
#include <variant>
#include <vector>

// the variant to visit
using var_t = std::variant<int, long, double, std::string>;

template <typename... Ts>
struct overload : Ts... {
  using Ts::operator()...;
};

// base types are deduced from passed arguments:
template <typename... Ts>
overload(Ts...) -> overload<Ts...>;

int main() {
  std::vector<var_t> vec = {10, 15l, 1.5, "hello"};

  for (auto& v : vec) {
    std::visit(
        overload{[](int arg) { std::cout << arg << ' '; },
                 [](long arg) { std::cout << arg << ' '; },
                 [](double arg) { std::cout << std::fixed << arg << ' '; },
                 [](const std::string& arg) {
                   std::cout << std::quoted(arg) << ' ';
                 }},
        v);
  }
  
  return 0;
}
