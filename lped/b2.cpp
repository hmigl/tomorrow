#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  const int N = 10;

  std::vector<std::pair<int, int>> v(N);
  int p1, p2;
  for (int i = 0; i < N; ++i) {
    std::cin >> p1 >> p2;
    v[i] = {p1, p2};
  }

  std::sort(v.begin(), v.end(), [](const auto &par1, const auto &par2) {
    int a = par1.first + par1.second;
    int b = par2.first + par2.second;

    if (a == b) {
      return par1.first < par2.first;
    }
    return a < b;
  });

  for (const auto &[p1, p2] : v) {
    std::cout << p1 << ' ' << p2 << " = " << p1 + p2 << '\n';
  }

  return 0;
}
