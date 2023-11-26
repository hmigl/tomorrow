#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  int N;
  std::cin >> N;

  auto s = N / 2;

  std::vector<int> c1(s), c2(s);
  for (auto i = 0; i < N / 2; ++i) {
    std::cin >> c1[i];
  }
  for (auto i = 0; i < N / 2; ++i) {
    std::cin >> c2[i];
  }

  std::sort(c1.begin(), c1.end());
  std::sort(c2.begin(), c2.end());

  std::vector<int> v_intersection;
  std::set_intersection(c1.begin(), c1.end(), c2.begin(), c2.end(),
                        std::back_inserter(v_intersection));

  auto v_intersection_size = v_intersection.size();
  if (v_intersection_size == s) {
    std::cout << "Azarado\n";
  } else if (!v_intersection_size) {
    std::cout << "Sortudo, ganhou os dois potes\n";
  } else {
    std::cout << "Ganhou um pote\n";
  }

  return 0;
}
