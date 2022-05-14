//
// Created by fabio on 09/05/22.
//
#include <fstream>
#include <filesystem>
#include "Multilingual.h"
#include <iostream>

int Multilingual::language = ENGLISH;

Multilingual *Multilingual::Instance() {
  static Multilingual singleton;
  return &singleton;
}
Multilingual::Multilingual() {
  english["header"] = "DUTCHNARY - choose the number of your option";
  english["panelOption1"] = "1 - Insert New Words";
  english["panelOption2"] = "2 - Update Words";
  english["panelOption3"] = "3 - Delete Words";
  english["panelOption4"] = "4 - Quiz Random";
  english["panelOption5"] = "5 - Options";
  english["panelOption6"] = "6 - Exit";

  english["insert1-1"] = "Please, write the word to insert:";

  english["option5-1"] = "English";
  english["option5-2"] = "Dutch";

  dutch["header"] = "DUTCHNARY - kies het nummer van uw optie";
  dutch["panelOption1"] = "1 - Nieuwe Woorden Invoegen";
  dutch["panelOption2"] = "2 - Update Woorden";
  dutch["panelOption3"] = "3 - Woorden verwijderen";
  dutch["panelOption4"] = "4 - Willekeurige Quiz";
  dutch["panelOption5"] = "5 - Opties";
  dutch["panelOption6"] = "6 - Uitgang";

  dutch["option5-1"] = "Engels";
  dutch["option5-2"] = "Nederlands";
}
std::string Multilingual::English(std::string key) {
  return Instance()->english[key];
}

std::string Multilingual::Dutch(std::string key) {
  return Instance()->dutch[key];
}
void Multilingual::setLanguage(int type) {
  if (1 == type) {
    language = ENGLISH;
  } else {
    language = DUTCH;
  }

}

//TODO modify the map to only one
void Multilingual::showEnglishPanel() {

  std::cout << Multilingual::English("header") << std::endl;
  std::cout << Multilingual::English("panelOption1") << std::endl;
  std::cout << Multilingual::English("panelOption2") << std::endl;
  std::cout << Multilingual::English("panelOption3") << std::endl;
  std::cout << Multilingual::English("panelOption4") << std::endl;
  std::cout << Multilingual::English("panelOption5") << std::endl;
  std::cout << Multilingual::English("panelOption6") << std::endl;

}

void Multilingual::showDutchPanel() {

  std::cout << Multilingual::Dutch("header") << std::endl;
  std::cout << Multilingual::Dutch("panelOption1") << std::endl;
  std::cout << Multilingual::Dutch("panelOption2") << std::endl;
  std::cout << Multilingual::Dutch("panelOption3") << std::endl;
  std::cout << Multilingual::Dutch("panelOption4") << std::endl;
  std::cout << Multilingual::Dutch("panelOption5") << std::endl;
  std::cout << Multilingual::Dutch("panelOption6") << std::endl;

}

void Multilingual::showInsertPanel() {

}
void Multilingual::showUpdatePanel() {

}
void Multilingual::showDeletePanel() {

}
void Multilingual::showQuizPanel() {

}
void Multilingual::showOptionsPanel() {

}
void Multilingual::showErrorInput(int input) {

}
