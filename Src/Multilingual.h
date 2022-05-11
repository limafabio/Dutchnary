//
// Created by fabio on 09/05/22.
//

#ifndef DUTCHNARY_SRC_MULTILINGUAL_H
#define DUTCHNARY_SRC_MULTILINGUAL_H
#include <map>

class Multilingual {

public:

  static Multilingual *Instance();
  static std::string English(std::string key);
  static std::string Dutch(std::string key);

private:

  Multilingual();

  std::map<std::string, std::string> english;
  std::map<std::string, std::string> dutch;

};
#endif //DUTCHNARY_SRC_MULTILINGUAL_H
