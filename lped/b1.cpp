#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  int n;
  std::cin >> n;

  std::vector<std::pair<int, int>> v;

  int id, grau;
  for (int i = 0; i < n; ++i) {
    std::cin >> id >> grau;
    v.push_back({id, grau});
  }

  std::sort(v.begin(), v.end(), [](const auto &lhs, const auto &rhs) {
    return lhs.second > rhs.second;
  });

  for (const auto &[id, grau] : v) {
    std::cout << id << ' ' << grau << '\n';
  }
  return 0;
}
