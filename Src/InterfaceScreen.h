//
// Created by fabio on 28/05/22.
//

#ifndef DUTCHNARY_SRC_INTERFACESCREEN_H
#define DUTCHNARY_SRC_INTERFACESCREEN_H

class InterfaceScreen {

public:

  static void showPanel();
  static int showInsertPanel();
  static int showUpdatePanel();
  static void showDeletePanel();
  static void showQuizPanel();
  static void showOptionsPanel();
  static void showErrorInput(std::string input);
  static void optionSelect(int option);

};

#endif //DUTCHNARY_SRC_INTERFACESCREEN_H
