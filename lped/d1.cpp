#include <iostream>
#include <queue>
#include <vector>

int main(void) {
  int n;
  std::cin >> n;
  std::queue<int> deck;
  for (int i = 0; i < n; ++i) {
    int e;
    std::cin >> e;
    deck.push(e);
  }

  int l, mortos = 0;
  std::cin >> l;
  std::vector<int> monstros_oponente(l);
  for (int i = 0; i < l; ++i) {
    std::cin >> monstros_oponente[i];
  }

  for (const auto &monstro_oponente : monstros_oponente) {
    if (deck.empty()) {
      break;
    }

    auto monstro_deck = deck.front();
    deck.pop();

    if (monstro_deck >= monstro_oponente) {
      deck.push(monstro_deck);
    } else {
      ++mortos;
    }
  }

  std::cout << mortos << '\n';
  return 0;
}
