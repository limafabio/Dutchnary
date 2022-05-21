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
  int n, option;

  do {
    Multilingual::showPanel();
    std::cin >> option;
  } while (6 != option);

  Word first, second;
  first.setId(1);
  first.setType("substantive");
  first.setMeaning("hello");
  first.setDutch("hallo");

  second.setId(2);
  second.setType("substantive");
  second.setMeaning("world");
  second.setDutch("wereld");

  Dictionary dict;
  dict.words.emplace_back(first);
  dict.words.emplace_back(second);
  //dict.writeWords();
  //dict.readWords();

  return 0;
}
