//
// Created by fabio on 09/05/22.
//
#include <fstream>
#include <filesystem>
#include "Multilingual.h"
#include <iostream>

Multilingual *Multilingual::Instance() {
  static Multilingual singleton;
  return &singleton;
}
Multilingual::Multilingual() {
  english["header"] = "DUTCHNARY";
  english["option1"] = "1 - Insert New Words";
  english["option2"] = "2 - Update Words";
  english["option3"] = "3 - Delete Words";
  english["option4"] = "4 - Quiz Random";
  english["option5"] = "5 - Options";
  english["option6"] = "6 - Exit";

  english["option5-1"] = "English";
  english["option5-2"] = "Dutch";

  dutch["header"] = "dutchnary";
  dutch["option1"] = "1 - Nieuwe Woorden Invoegen";
  dutch["option2"] = "2 - Update Woorden";
  dutch["option3"] = "3 - Woorden verwijderen";
  dutch["option4"] = "4 - Willekeurige Quiz";
  dutch["option5"] = "5 - Opties";
  dutch["option6"] = "6 - Uitgang";

  dutch["option5-1"] = "Engels";
  dutch["option5-2"] = "Nederlands";

}
std::string Multilingual::English(std::string key) {
  return Instance()->english[key];
}

std::string Multilingual::Dutch(std::string key) {
  return Instance()->dutch[key];
}
