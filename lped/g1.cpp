#include <iostream>
#include <map>
#include <string>
#include <vector>

int main(void) {
  int n;
  std::cin >> n;

  std::cin.ignore();
  std::vector<std::string> frases;
  for (auto i = 0; i < n; ++i) {
    std::string s;
    std::getline(std::cin, s);
    frases.push_back(s);
  }

  std::map<std::string, int> palavras_e_ocorrencias;
  auto pos = 0;
  for (auto &s : frases) {
    while ((pos = s.find(" ")) != std::string::npos) {
      palavras_e_ocorrencias[s.substr(0, pos)]++;
      s.erase(0, pos + 1);
    }
    palavras_e_ocorrencias[s.substr(0, pos)]++;
  }

  int i = 0;
  for (const auto &[key, val] : palavras_e_ocorrencias) {
    if (val == 1) {
      ++i;
    }
  }
  std::cout << i << '\n';
  for (const auto &[key, val] : palavras_e_ocorrencias) {
    if (val == 1) {
      std::cout << key << '\n';
    }
  }

  return 0;
}
