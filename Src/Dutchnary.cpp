#include <iostream>
#include <Word.h>
#include <Dictionary.h>

int main() {
  
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
  dict.writeWords();
  dict.readWords();

  std::cout << "Hallo";
  return 0;
}
