#include <iostream>
#include <Word.h>
#include <Dictionary.h>
#include <Multilingual.h>
#include <InterfaceScreen.h>
#include <cstdlib>

void clear_screen() {
#ifdef WINDOWS
  std::system("cls");
#else
  std::system("clear");
#endif
}

int main() {
  int n, input;
  Dictionary *dict = Dictionary::Instance();
  dict->readWords();

  do {
    clear_screen();
    InterfaceScreen::showPanel();
    std::cin >> input;
    InterfaceScreen::optionSelect(input);
  } while (6 != input);

  dict->writeWords();

  //TODO SAVE THE DATABASE, TEST DELETE
  std::cout << "Doei, Tot ziens in Nederlands !! " << std::endl;
  return 0;
}
