#include <iostream>
#include <stack>

int main(void) {
  int n;
  std::cin >> n;

  std::stack<int> desafiante, adversario;
  for (auto i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    desafiante.push(x);
  }

  for (auto i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    adversario.push(x);
  }

  while (!desafiante.empty() && !adversario.empty()) {
    auto carta_des = desafiante.top();
    auto carta_adv = adversario.top();

    desafiante.pop();
    adversario.pop();

    if (carta_des > carta_adv) {
      carta_des -= carta_adv;
      desafiante.push(carta_des);
    } else if (carta_adv > carta_des) {
      carta_adv -= carta_des;
      adversario.push(carta_adv);
    }
  }

  if (adversario.empty()) {
    std::cout << "Eu " << n - desafiante.size() << '\n';
  } else {
    std::cout << "Adversario " << n - adversario.size() << '\n';
  }

  return 0;
}
