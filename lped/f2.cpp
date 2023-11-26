#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

int main(void) {
  int n;
  std::cin >> n;
  std::cin.ignore();
  std::vector<std::string> antes;
  for (auto i = 0; i < n; ++i) {
    std::string str;
    std::getline(std::cin, str);
    antes.push_back(str);
  }

  int m;
  std::cin >> m;
  std::cin.ignore();
  std::set<std::string> s;
  for (auto i = 0; i < m; ++i) {
    std::string str;
    std::getline(std::cin, str);
    s.insert(str);
  }

  std::sort(antes.begin(), antes.end());

  std::vector<std::string> diff;
  std::set_difference(antes.begin(), antes.end(), s.begin(), s.end(),
                      std::inserter(diff, diff.begin()));

  for (auto i = 0; i < diff.size(); ++i) {
    std::cout << diff[i] << '\n';
  }
  for (auto it = s.begin(); it != s.end(); ++it) {
    std::cout << *it << '\n';
  }

  return 0;
}
