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
  phraseToShow["ENGLISH"]["insert-duplicate"] = "Word already insert in dictionary";

  phraseToShow["ENGLISH"]["update-dutch-english"] = "Please, write 1 for dutch word or 2 for english word ";
  phraseToShow["ENGLISH"]["update-dutch"] = "Please, write the word in dutch to update";
  phraseToShow["ENGLISH"]["update-meaning"] = "Please, write the word in english to update";
  phraseToShow["ENGLISH"]["update-type"] = " Please, write the type of the word to update ";
  phraseToShow["ENGLISH"]["update-sound"] = " Please, write the sound of the word to update ";
  phraseToShow["ENGLISH"]["update-sucess"] = "Word was update ";
  phraseToShow["ENGLISH"]["update-wrong"] = "Word was not update ";
  phraseToShow["ENGLISH"]["update-wrong-input"] = "Wrong input ";
  phraseToShow["ENGLISH"]["update-question-meaning"] = "Do you like update the meaning ?";
  phraseToShow["ENGLISH"]["update-question-type"] = "Do you like update the type ?";
  phraseToShow["ENGLISH"]["update-question-sound"] = "Do you like update the sound ?";

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

  phraseToShow["ENGLISH"]["error-1"] = "Please, write just number";

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
std::string Multilingual::showPhrases(std::string key) {

  std::string phrase;
  Multilingual *obj = Multilingual::Instance();
  std::map<std::string, std::map<std::string, std::string>>::iterator it_language;
  it_language = obj->phraseToShow.find(language);
  if (obj->phraseToShow.end() != it_language) {
    std::map<std::string, std::string>::iterator it_key;
    it_key = it_language->second.find(key);
    if (it_language->second.end() != it_key) {
      phrase = it_key->second;
    }
  }
  return phrase;
}

void toLowerCase(std::string word) {

  std::for_each(word.begin(), word.end(), [](char &c) {
    c = ::tolower(c);
  });

}
