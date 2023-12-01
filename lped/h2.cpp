#include <iostream>
#include <queue>
#include <string>
#include <vector>

using std::string, std::pair, std::vector, std::priority_queue;

struct Grifinoria {
  bool operator()(const pair<string, int> &lhs, const pair<string, int> &rhs) {
    return lhs.second < rhs.second;
  }
};

struct Sonserina {
  bool operator()(const pair<string, int> &lhs, const pair<string, int> &rhs) {
    return lhs.second > rhs.second;
  }
};

int main(void) {
  int n;
  std::cin >> n;
  std::cin.ignore();

  priority_queue<pair<string, int>, vector<pair<string, int>>, Grifinoria>
      pqGrif;
  priority_queue<pair<string, int>, vector<pair<string, int>>, Sonserina>
      pqSons;

  for (auto i = 0; i < n; ++i) {
    int g, s, m;
    std::cin >> g >> s >> m;

    for (auto j = 0; j < g; ++j) {
      int hab;
      std::string nome;
      std::cin >> hab;
      std::getline(std::cin >> std::ws, nome);

      pqGrif.push({nome, hab});
    }
    for (auto j = 0; j < s; ++j) {
      int hab;
      std::string nome;
      std::cin >> hab;
      std::getline(std::cin >> std::ws, nome);

      pqSons.push({nome, hab});
    }

    for (auto k = 0; k < m && (!pqGrif.empty() && !pqSons.empty()); ++k) {
      std::cout << pqGrif.top().first << " e " << pqSons.top().first << '\n';
      pqGrif.pop();
      pqSons.pop();
    }
  }
  return 0;
}
