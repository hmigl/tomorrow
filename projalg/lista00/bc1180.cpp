#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  int n;
  std::cin >> n;

  std::vector<int> v(n);
  for (auto i = 0; i < n; ++i) {
    std::cin >> v[i];
  }

  auto it = std::min_element(v.begin(), v.end());
  std::cout << "Menor valor: " << *it << '\n';
  std::cout << "Posicao: " << std::distance(v.begin(), it) << '\n';
  return 0;
}
