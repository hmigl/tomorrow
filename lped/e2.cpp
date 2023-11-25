#include <iostream>
#include <stack>
#include <string>

bool comb(const std::string &b1, const std::string &b2) {
  for (auto i = 0; i < 3; ++i) {
    if (b1[i] == b2[i]) {
      return false;
    }
  }
  return true;
}

int main(void) {
  int num_blocos, alt_max;
  std::cin >> num_blocos >> alt_max;

  int points = 0;
  std::stack<std::string> blocks;

  int i = -1;
  while (++i < num_blocos) {
    std::string x;
    std::cin >> x;

    blocks.push(x);

    if (alt_max == 1) {
      break;
    }

    if (blocks.size() < 2) {
      continue;
    }

    std::string b1 = blocks.top();
    blocks.pop();
    std::string b2 = blocks.top();
    blocks.pop();

    if (comb(b1, b2)) {
      points += 10;
    } else {
      blocks.push(b2);
      blocks.push(b1);

      if (blocks.size() == alt_max) {
        break;
      }
    }
  }

  if (blocks.size() < alt_max) {
    std::cout << points << '\n';
  } else {
    std::cout << "game over\n";
  }

  return 0;
}
