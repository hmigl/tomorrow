#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int main(void) {
  int n;
  std::cin >> n;
  std::cin.ignore();

  std::unordered_map<std::string, std::string> map;
  for (auto i = 0; i < n; ++i) {
    std::string str;
    std::getline(std::cin, str);
    auto pos = str.find(" ");
    map[str.substr(0, pos)] = str.substr(pos + 1);
  }

  int m;
  std::cin >> m;
  std::cin.ignore();
  std::vector<std::string> v(m);
  for (auto i = 0; i < m; ++i) {
    std::cin >> v[i];
  }

  for (const auto &s : v) {
    if (auto it = map.find(s); it != map.end()) {
      std::cout << it->second << ' ';
    } else {
      std::cout << s << ' ';
    }
  }
  std::cout << '\n';

  return 0;
}
