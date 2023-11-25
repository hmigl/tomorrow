#include <deque>
#include <iostream>

int main(void) {
  int n, m;
  std::cin >> n >> m;

  std::deque<int> q;
  for (auto i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    q.push_back(x);
  }

  const int Q = 1;
  for (auto i = 0; i < m; ++i) {
    if (q.empty()) {
      break;
    }

    auto tempo_exec = q.front();
    q.pop_front();

    tempo_exec -= Q;
    if (tempo_exec) {
      q.push_back(tempo_exec);
    }
  }

  if (q.empty()) {
    std::cout << "pronto\n";
  } else {
    std::cout << q.size() << '\n';
    for (const auto &e : q) {
      std::cout << e << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}
