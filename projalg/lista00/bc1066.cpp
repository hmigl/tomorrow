#include <iostream>

int main(void) {
  constexpr int N = 5;
  int pares = 0, impares = 0, pos = 0, neg = 0;

  for (auto i = 0; i < N; ++i) {
    int x;
    std::cin >> x;

    if (x % 2) {
      ++impares;
    } else {
      ++pares;
    }

    if (x < 0) {
      ++neg;
    } else if (x > 0) {
      ++pos;
    }
  }

  std::cout << pares << " valor(es) par(es)\n";
  std::cout << impares << " valor(es) impar(es)\n";
  std::cout << pos << " valor(es) positivo(s)\n";
  std::cout << neg << " valor(es) negativo(s)\n";

  return 0;
}
