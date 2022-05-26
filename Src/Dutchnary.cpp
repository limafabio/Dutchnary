#include <iostream>
#include <Word.h>
#include <Dictionary.h>
#include <Multilingual.h>
#include <cstdlib>

void clear_screen() {
#ifdef WINDOWS
  std::system("cls");
#else
  std::system("clear");
#endif
}

void optionSelect(int option) {
  switch (option) {
  case 1: Multilingual::showInsertPanel();
    break;
  case 2: Multilingual::showUpdatePanel();
    break;
  case 3: Multilingual::showDeletePanel();
    break;
  case 4: Multilingual::showQuizPanel();
    break;
  case 5: Multilingual::showOptionsPanel();
    break;
  default: Multilingual::showErrorInput(option);

  }
}

int main() {
  int n, input;

  do {
    clear_screen();
    Multilingual::showPanel();
    std::cin >> input;
    optionSelect(input);
  } while (6 != input);

  std::cout << "doei !! " << std::endl;

  return 0;
}
