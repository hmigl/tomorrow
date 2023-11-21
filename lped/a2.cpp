#include <iostream>
#include <vector>

int main(void) {
  int n;
  std::cin >> n;

  std::vector<int> xps(n);
  std::vector<int> bonus(n);

  for (int i = 0; i < n; ++i) {
    std::cin >> xps[i];
  }

  for (int i = 0; i < n; ++i) {
    std::cin >> bonus[i];
  }

  int xp_necessario, bonus_adicional;
  std::cin >> xp_necessario >> bonus_adicional;

  int total = 0;
  for (int i = 0; i < n; ++i) {
    total += xps[i] * (bonus_adicional + bonus[i]);
  }

  if (total >= xp_necessario) {
    std::cout << "Upou de Nivel!\n";
  } else {
    std::cout << "Nao foi dessa vez!\n";
  }
  return 0;
}
