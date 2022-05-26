//
// Created by fabio on 09/05/22.
//
#include <fstream>
#include <filesystem>
#include "Multilingual.h"
#include <iostream>
#include "Word.h"
#include "Dictionary.h"

std::string Multilingual::language = "ENGLISH";

Multilingual *Multilingual::Instance() {
  static Multilingual singleton;
  return &singleton;
}
Multilingual::Multilingual() {

  phraseToShow["ENGLISH"]["header"] = "DUTCHNARY - choose the number of your option";
  phraseToShow["ENGLISH"]["panelOption1"] = "1 - Insert New Words";
  phraseToShow["ENGLISH"]["panelOption2"] = "2 - Update Words";
  phraseToShow["ENGLISH"]["panelOption3"] = "3 - Delete Words";
  phraseToShow["ENGLISH"]["panelOption4"] = "4 - Quiz Random";
  phraseToShow["ENGLISH"]["panelOption5"] = "5 - Options";
  phraseToShow["ENGLISH"]["panelOption6"] = "6 - Exit";
  phraseToShow["ENGLISH"]["correct"] = "Correct answer";
  phraseToShow["ENGLISH"]["wrong"] = "Wrong answer";
  phraseToShow["ENGLISH"]["wrong-input"] = "Wrong input";

  phraseToShow["ENGLISH"]["insert-dutch"] = "Please, write the word in dutch to insert :";
  phraseToShow["ENGLISH"]["insert-type"] = "Please, write the type of word in english :";
  phraseToShow["ENGLISH"]["insert-meaning"] = "Please, write the meaning of word in english :";
  phraseToShow["ENGLISH"]["insert-sound"] = "Please, write the sound of word in english :";
  phraseToShow["ENGLISH"]["insert-sucess"] = "Word was insert";

  phraseToShow["ENGLISH"]["update-dutch"] = "Please, write the word in dutch to update";
  phraseToShow["ENGLISH"]["update-field"] = "Which field do you want update ? ";
  phraseToShow["ENGLISH"]["update-meaning"] = "Please, write the word to update ";
  phraseToShow["ENGLISH"]["update-sucess"] = "Word was update ";

  phraseToShow["ENGLISH"]["delete-dutch"] = "Please, write the word in dutch to delete";
  phraseToShow["ENGLISH"]["delete-meaning"] = "Please, write the meaning of the word to delete";
  phraseToShow["ENGLISH"]["delete-sound"] = "Please, write the sound of word";
  phraseToShow["ENGLISH"]["delete-sucess"] = "Word was delete";

  phraseToShow["ENGLISH"]["option-0"] = "Please, choose the option to configure : ";
  phraseToShow["ENGLISH"]["option-1"] = "1 - For change the language to show the phrases. ";
  phraseToShow["ENGLISH"]["option-2"] = "2 - For change the level of the quizz. ";

  phraseToShow["ENGLISH"]["quiz-language"] = "Select if you want dutch ou english word: 1- english, 2 - dutch ";
  phraseToShow["ENGLISH"]["quiz"] = "Which meanings this world in ";

  phraseToShow["ENGLISH"]["option-1-1"] = "Select:  1 English 2 Dutch ";
  phraseToShow["ENGLISH"]["option-2-2"] = "Write the level of the quizz between 0 and 5";

  phraseToShow["ENGLISH"]["option5-1"] = "English";
  phraseToShow["ENGLISH"]["option5-2"] = "Dutch";

  phraseToShow["DUTCH"]["header"] = "DUTCHNARY - kies het nummer van uw optie";
  phraseToShow["DUTCH"]["panelOption1"] = "1 - Nieuwe Woorden Invoegen";
  phraseToShow["DUTCH"]["panelOption2"] = "2 - Update Woorden";
  phraseToShow["DUTCH"]["panelOption3"] = "3 - Woorden verwijderen";
  phraseToShow["DUTCH"]["panelOption4"] = "4 - Willekeurige Quiz";
  phraseToShow["DUTCH"]["panelOption5"] = "5 - Opties";
  phraseToShow["DUTCH"]["panelOption6"] = "6 - Uitgang";

  phraseToShow["DUTCH"]["insert-dutch"] = "Schrijf het woord in het nederlands om in te voegen:";
  phraseToShow["DUTCH"]["insert-type"] = "Schrijf alsjeblieft het soort woord in het Engels:";
  phraseToShow["DUTCH"]["insert-meaning"] = "Schrijf alstublieft de betekenis van het woord in het Engels:";
  phraseToShow["DUTCH"]["insert-sound"] = "Schrijf alsjeblieft het geluid van het woord in het Engels :";

  phraseToShow["DUTCH"]["update-dutch"] = "Schrijf het woord in het nederlands om te updaten";
  phraseToShow["DUTCH"]["update-field"] = "Welk veld wil je updaten?";
  phraseToShow["DUTCH"]["update-meaning"] = "Schrijf alsjeblieft het woord om te updaten ";

  phraseToShow["DUTCH"]["delete-dutch"] = "Schrijf alsjeblieft het woord in het nederlands om te verwijderen";
  phraseToShow["DUTCH"]["delete-meaning"] = "Schrijf alstublieft de betekenis van het woord dat u wilt verwijderen";
  phraseToShow["DUTCH"]["delete-sound"] = "Schrijf alsjeblieft het geluid van het woord";

  phraseToShow["DUTCH"]["option-0"] = "Kies alstublieft de optie om te configureren : ";
  phraseToShow["DUTCH"]["option-1"] = "1 - Voor het wijzigen van de taal om de zinnen weer te geven.";
  phraseToShow["DUTCH"]["option-2"] = "2 - Voor het wijzigen van het niveau van de quiz.";

  phraseToShow["DUTCH"]["option5-1"] = "Engels";
  phraseToShow["DUTCH"]["option5-2"] = "Nederlands";
}

void Multilingual::setLanguage(std::string type) {
  if ("ENGLISH" == type) {
    language = "ENGLISH";
  } else {
    language = "DUTCH";
  }

}

void Multilingual::showPanel() {

  Multilingual *obj = Multilingual::Instance();
  std::cout << obj->phraseToShow[language]["header"] << std::endl;
  std::cout << obj->phraseToShow[language]["panelOption1"] << std::endl;
  std::cout << obj->phraseToShow[language]["panelOption2"] << std::endl;
  std::cout << obj->phraseToShow[language]["panelOption3"] << std::endl;
  std::cout << obj->phraseToShow[language]["panelOption4"] << std::endl;
  std::cout << obj->phraseToShow[language]["panelOption5"] << std::endl;
  std::cout << obj->phraseToShow[language]["panelOption6"] << std::endl;

}

void Multilingual::showInsertPanel() {

  Multilingual *obj = Multilingual::Instance();
  Word wordToInsert;
  std::cout << obj->phraseToShow[language]["insert-dutch"] << std::endl;
  std::cin >> wordToInsert.dutch;
  std::cout << obj->phraseToShow[language]["insert-meaning"] << std::endl;
  std::cin >> wordToInsert.meaning;
  std::cout << obj->phraseToShow[language]["insert-type"] << std::endl;
  std::cin >> wordToInsert.type;
  std::cout << obj->phraseToShow[language]["insert-sound"] << std::endl;
  std::cin >> wordToInsert.sound;
  //TODO SAVE THE WORD IN CASE THE WORD DOES NOT IN DATABASE
  std::cout << obj->phraseToShow[language]["insert-sucess"] << std::endl;

}
void Multilingual::showUpdatePanel() {

  Multilingual *obj = Multilingual::Instance();
  Word wordToUpdate;
  std::string field;

  std::cout << obj->phraseToShow[language]["update-dutch"] << std::endl;
  std::cin >> wordToUpdate.dutch;
  std::cout << obj->phraseToShow[language]["update-field"] << std::endl;
  std::cin >> field;
  //TODO SEARCH THE WORD IN DATABASE
  std::cout << obj->phraseToShow[language]["update-sucess"] << std::endl;

}
void Multilingual::showDeletePanel() {

  Multilingual *obj = Multilingual::Instance();
  Word wordToDelete;
  std::cout << obj->phraseToShow[language]["delete-dutch"] << std::endl;
  std::cin >> wordToDelete.dutch;
  //TODO SEARCH THE WORD IN DATABASE AND DELETE
  std::cout << obj->phraseToShow[language]["delete-sucess"] << std::endl;

}
void Multilingual::showQuizPanel() {
  Multilingual *obj = Multilingual::Instance();
  int wordLanguage;
  std::string dutchWord, englishWord;
  Word quiz;

  std::cout << obj->phraseToShow[language]["quiz-language"] << std::endl;
  std::cin >> wordLanguage;
  if (1 == wordLanguage) {
    std::cout << obj->phraseToShow[language]["quiz"] + " english" << std::endl;
    std::cin >> englishWord;
    if (englishWord == quiz.meaning) {
      std::cout << obj->phraseToShow[language]["correct"] << std::endl;
    } else {
      std::cout << obj->phraseToShow[language]["wrong"] << std::endl;
    }
  } else if (2 == wordLanguage) {
    std::cout << obj->phraseToShow[language]["quiz"] + " dutch" << std::endl;
    std::cout << dutchWord;
    if (dutchWord == quiz.dutch) {
      std::cout << obj->phraseToShow[language]["correct"] << std::endl;
      //TODO DECREASE THE PRIORITY
    } else {
      std::cout << obj->phraseToShow[language]["wrong"] << std::endl;
      //TODO INCREASE THE PRIORITY
    }
  } else {
    std::cout << obj->phraseToShow[language]["wrong-input"] << std::endl;
  }

}
void Multilingual::showOptionsPanel() {

  Multilingual *obj = Multilingual::Instance();
  int option, config;

  std::cout << obj->phraseToShow[language]["option-0"] << std::endl;
  std::cout << obj->phraseToShow[language]["option-1"] << std::endl;
  std::cout << obj->phraseToShow[language]["option-2"] << std::endl;
  std::cin >> option;

  if (1 == option) {
    std::cout << obj->phraseToShow[language]["option-1-1"] << std::endl;
    std::cin >> config;
    if (1 == config) {
      //TODO CONFIGURE THE LANGUAGE
    } else {

    }

  }
  if (2 == option) {
    std::cout << obj->phraseToShow[language]["option-2-1"] << std::endl;
    std::cin >> config;
    //TODO CONFIGURE QUIZ LEVEL

  }

}
void Multilingual::showErrorInput(int input) {

}
