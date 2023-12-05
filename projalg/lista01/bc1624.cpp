#include <iostream>
#include <vector>

int g(const std::vector<int> &precos, const std::vector<int> &pesos,
      int pesoMax, int i) {
  if (i <= 0) {
    return 0;
  }

  if (pesos[i] > pesoMax) {  // nao consegue carregar, tenta o prox
    return g(precos, pesos, pesoMax, i - 1);
  } else {  // consegue carregar
    return std::max(g(precos, pesos, pesoMax, i - 1),
                    precos[i] + g(precos, pesos, pesoMax - pesos[i], i - 1));
  }
}

void f(int n) {
  std::vector<int> precos(n + 1), pesos(n + 1);
  precos[0] = pesos[0] = 0;

  for (auto i = 1; i < n + 1; ++i) {
    std::cin >> precos[i] >> pesos[i];
  }

  int pesoMax;
  std::cin >> pesoMax;

  std::cout << g(precos, pesos, pesoMax, n) << '\n';
}

int main(void) {
  for (;;) {
    int n;
    std::cin >> n;
    if (!n) {
      break;
    }
    f(n);
  }
  return 0;
}
