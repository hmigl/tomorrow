#include <iostream>
#include <queue>
#include <vector>

using std::string, std::pair, std::vector, std::priority_queue;

struct Order {
  bool operator()(const pair<string, int> &lhs, const pair<string, int> &rhs) {
    return lhs.second < rhs.second;
  }
};

int main(void) {
  int d, x;
  std::cin >> d >> x;

  priority_queue<pair<string, int>, vector<pair<string, int>>, Order> pq;
  vector<pair<string, int>> atendidos;

  for (auto i = 0; i < d; ++i) {
    int n;
    std::cin >> n;

    for (auto j = 0; j < n; ++j) {
      string nome;
      int idade;
      std::cin >> nome >> idade;

      pq.push({nome, idade});
    }

    for (auto k = 0; k < x && !pq.empty(); ++k) {
      atendidos.push_back(pq.top());
      pq.pop();
    }
  }

  for (const auto &[nome, idade] : atendidos) {
    std::cout << nome << '\n';
  }

  return 0;
}
