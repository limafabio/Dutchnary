//
// Created by fabio on 09/05/22.
//

#ifndef DUTCHNARY_SRC_MULTILINGUAL_H
#define DUTCHNARY_SRC_MULTILINGUAL_H
#include <map>

class Multilingual {

public:

  static Multilingual *Instance();
  static void setLanguage(std::string type);
  static void toLowerCase(std::string word);
  std::string showPhrases(std::string phrase);

private:

  Multilingual();
  std::map<std::string, std::map<std::string, std::string>> phraseToShow;
  static std::string language;
};
#endif //DUTCHNARY_SRC_MULTILINGUAL_H
