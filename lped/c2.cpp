#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  int livros;
  std::cin >> livros;

  std::string codigo;
  int status;
  std::vector<std::pair<std::string, int>> v;
  for (int i = 0; i < livros; ++i) {
    std::cin >> codigo >> status;
    v.push_back({codigo, status});
  }

  int req;
  std::cin >> req;
  std::vector<std::string> codigos(req);
  for (int i = 0; i < req; ++i) {
    std::cin >> codigos[i];
  }

  std::vector<std::string> res;
  for (const auto &e : codigos) {
    auto it = std::lower_bound(
        v.begin(), v.end(), e,
        [](const auto &p, const auto &key) { return p.first < key; });

    if (it != v.end() && it->first == e) {
      it->second == 1 ? res.push_back("Disponivel")
                      : res.push_back("Emprestado");
    } else {
      res.push_back("Nao encontrado");
    }
  }

  for (const auto &e : res) {
    std::cout << e << '\n';
  }

  return 0;
}
