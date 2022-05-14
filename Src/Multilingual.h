//
// Created by fabio on 09/05/22.
//

#ifndef DUTCHNARY_SRC_MULTILINGUAL_H
#define DUTCHNARY_SRC_MULTILINGUAL_H
#include <map>
#define ENGLISH 1
#define DUTCH 2

class Multilingual {

public:

  static Multilingual *Instance();
  static std::string English(std::string key);
  static std::string Dutch(std::string key);
  static void setLanguage(int type);
  static void showEnglishPanel();
  static void showDutchPanel();
  static void showInsertPanel();
  static void showUpdatePanel();
  static void showDeletePanel();
  static void showQuizPanel();
  static void showOptionsPanel();
  static void showErrorInput(int input);

private:

  Multilingual();

  std::map<std::string, std::string> english;
  std::map<std::string, std::string> dutch;
  static int language;

};
#endif //DUTCHNARY_SRC_MULTILINGUAL_H
