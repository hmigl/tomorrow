#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  int n;
  std::cin >> n;
  std::vector<std::pair<std::string, int>> v;

  std::string nome = "";
  int peso = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> nome >> peso;
    if (nome == "Bilbo") {  // 'O peso do Bilbo será ignorado.'
      continue;
    }
    v.push_back({nome, peso});
  }

  int capacidade = 0;
  std::cin >> capacidade;
  auto excede_capacidade = std::find_if(
      v.begin(), v.end(),
      [&capacidade](const auto &x) { return x.second > capacidade; });

  if (excede_capacidade == v.end()) {
    std::cout << "Vamos todos encontrar a montanha!\n";
  } else {
    std::cout << "Vamos virar almoço de aranhas gigantes!\n";
    for (const auto &[nome, peso] : v) {
      if (peso > capacidade) {
        std::cout << nome << '\n';
      }
    }
  }
}
