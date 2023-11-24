#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  int n;
  std::cin >> n;

  std::vector<std::string> gerais(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> gerais[i];
  }

  std::cin >> n;
  std::vector<std::string> proibidos(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> proibidos[i];
  }

  std::cin >> n;
  std::vector<std::string> consultas(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> consultas[i];
  }

  std::vector<std::string> classificacoes;
  for (const auto &runa : consultas) {
    if (std::binary_search(gerais.begin(), gerais.end(), runa)) {
      classificacoes.push_back("Geral");
    } else {
      classificacoes.push_back("Proibido");
    }
  }

  for (const auto &tipo : classificacoes) {
    std::cout << tipo << '\n';
  }

  return 0;
}
