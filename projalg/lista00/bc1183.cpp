#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

int main(void) {
  char op;
  std::cin >> op;

  int constexpr T = 12;
  int constexpr elemensDiag = ((T * T) - T) / 2;

  std::vector<std::vector<double>> m;

  for (auto i = 0; i < T; ++i) {
    std::vector<double> v(T);
    for (auto j = 0; j < T; ++j) {
      std::cin >> v[j];
    }
    m.push_back(v);
  }

  double s = 0;
  for (auto i = 0; i < T - 1; ++i) {
    s += std::accumulate(m[i].begin() + (i + 1), m[i].end(), 0.0);
  }

  if (op == 'M') {
    s /= elemensDiag;
  }

  std::cout << std::fixed;
  std::cout << std::setprecision(1);
  std::cout << s << '\n';

  return 0;
}
