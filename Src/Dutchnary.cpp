#include <iostream>
#include <Word.h>
#include <Dictionary.h>
#include <Multilingual.h>

int main() {
  int n;

  std::cout << Multilingual::English("header") << std::endl;
  std::cout << Multilingual::Dutch("header") << std::endl;

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
