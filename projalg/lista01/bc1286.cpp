#include <algorithm>
#include <iostream>
#include <vector>

// TODO: otimizar com memoization
int g(const std::vector<int> &tempos, const std::vector<int> &pizzas, int p,
      int i) {
  if (i <= 0) {
    return 0;
  }

  if (pizzas[i] > p) {
    return g(tempos, pizzas, p,
             i - 1);  // nao consegue pegar, tente outro pedido
  } else {
    // qual a melhor opcao?
    return std::max(
        // nao pegar esse e tentar fazer outro pedido
        g(tempos, pizzas, p, i - 1),

        // ou pegar e acumular o proximo pedido
        tempos[i] + g(tempos, pizzas, p - pizzas[i], i - 1));
  }
}

void f(int n, int p) {
  std::vector<int> tempos, pizzas;
  tempos.push_back(0);
  pizzas.push_back(0);

  for (auto i = 0; i < n; ++i) {
    int totalTempo, qtdPizza;
    std::cin >> totalTempo >> qtdPizza;
    tempos.push_back(totalTempo);
    pizzas.push_back(qtdPizza);
  }

  int mins = g(tempos, pizzas, p, n);
  std::cout << mins << " min.\n";
}

int main(void) {
  for (;;) {
    int n, p;
    std::cin >> n;
    if (!n) {
      break;
    }
    std::cin >> p;
    f(n, p);
  }

  return 0;
}
