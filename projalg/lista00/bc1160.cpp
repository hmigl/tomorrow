#include <iostream>

int main(void) {
  int T;
  std::cin >> T;

  for (auto i = 0; i < T; ++i) {
    int pa, pb, anos = 0;
    double g1, g2;

    std::cin >> pa >> pb >> g1 >> g2;

    double c1 = 1 + (g1 / 100), c2 = 1 + (g2 / 100);

    while ((pa <= pb) && (++anos <= 100)) {
      pa *= c1;
      pb *= c2;
    }

    if (anos > 100) {
      std::cout << "Mais de 1 seculo.\n";
    } else {
      std::cout << anos << " anos.\n";
    }
  }

  return 0;
}
