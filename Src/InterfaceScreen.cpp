//
// Created by fabio on 28/05/22.
//



#include <iostream>
#include "InterfaceScreen.h"
#include "Multilingual.h"
#include "Word.h"
#include "Dictionary.h"

void InterfaceScreen::showPanel() {

  Multilingual *obj = Multilingual::Instance();
  std::cout << obj->showPhrases("header") << std::endl;
  std::cout << obj->showPhrases("panelOption1") << std::endl;
  std::cout << obj->showPhrases("panelOption2") << std::endl;
  std::cout << obj->showPhrases("panelOption3") << std::endl;
  std::cout << obj->showPhrases("panelOption4") << std::endl;
  std::cout << obj->showPhrases("panelOption5") << std::endl;
  std::cout << obj->showPhrases("panelOption6") << std::endl;

}

void InterfaceScreen::optionSelect(int option) {
  switch (option) {
  case 1: InterfaceScreen::showInsertPanel();
    break;
  case 2: InterfaceScreen::showUpdatePanel();
    break;
  case 3: InterfaceScreen::showDeletePanel();
    break;
  case 4: InterfaceScreen::showQuizPanel();
    break;
  case 5: InterfaceScreen::showOptionsPanel();
    break;
  default: InterfaceScreen::showErrorInput(option);

  }
}

void InterfaceScreen::showInsertPanel() {

  Dictionary *dict = Dictionary::Instance();
  Multilingual *obj = Multilingual::Instance();
  Word wordToInsert;
  std::cout << obj->showPhrases("insert-dutch") << std::endl;
  std::cin >> wordToInsert.dutch;
  std::cout << obj->showPhrases("insert-meaning") << std::endl;
  std::cin >> wordToInsert.meaning;
  std::cout << obj->showPhrases("insert-type") << std::endl;
  std::cin >> wordToInsert.type;
  std::cout << obj->showPhrases("insert-sound") << std::endl;
  std::cin >> wordToInsert.sound;
  wordToInsert.toLowerWord();
  if (false == dict->wordIsDictionary(wordToInsert.dutch)) {
    if (dict->insertWord(wordToInsert)) {
      std::cout << obj->showPhrases("insert-sucess") << std::endl;
    }
  }
  std::cout << obj->showPhrases("insert-duplicate") << std::endl;
}

void InterfaceScreen::showUpdatePanel() {

  Multilingual *obj = Multilingual::Instance();
  Word wordToUpdate;
  std::string field, fieldToUpdate;
  Dictionary *dict = Dictionary::Instance();

  std::cout << obj->showPhrases("update-dutch") << std::endl;
  std::cin >> fieldToUpdate;
  std::cout << obj->showPhrases("update-field") << std::endl;
  std::cin >> field;
  if (true == dict->wordIsDictionary(wordToUpdate.getDutch())) {
    //TODO UPDATE THE WORD
    wordToUpdate = dict->searchDutchWord(wordToUpdate.getDutch());
    std::cout << obj->showPhrases("update-sucess") << std::endl;
  } else {
    std::cout << obj->showPhrases("update-wrong") << std::endl;
  }

}

void InterfaceScreen::showDeletePanel() {

  Multilingual *obj = Multilingual::Instance();
  Word wordToDelete;
  Dictionary *dict = Dictionary::Instance();

  std::cout << obj->showPhrases("delete-dutch") << std::endl;
  std::cin >> wordToDelete.dutch;
  if (true == dict->wordIsDictionary(wordToDelete.getDutch())) {
    //TODO SEARCH THE WORD IN DATABASE AND DELETE

  }
  std::cout << obj->showPhrases("delete-sucess") << std::endl;
}

void InterfaceScreen::showErrorInput(int input) {

  //TODO MAKE DEAL WITH LETTERS
  Multilingual *obj = Multilingual::Instance();
  std::cout << obj->showPhrases("error-1") << std::endl;
  input = 6;
  std::cout << "INPUT: " + input << std::endl;

}

void InterfaceScreen::showOptionsPanel() {

  Multilingual *obj = Multilingual::Instance();
  int option, config;

  std::cout << obj->showPhrases("option-0") << std::endl;
  std::cout << obj->showPhrases("option-1") << std::endl;
  std::cout << obj->showPhrases("option-2") << std::endl;
  std::cin >> option;

  if (1 == option) {
    std::cout << obj->showPhrases("option-1-1") << std::endl;
    std::cin >> config;
    if (1 == config) {
      //TODO CONFIGURE THE LANGUAGE
    } else {

    }
  }
  if (2 == option) {
    std::cout << obj->showPhrases("option-2-1") << std::endl;
    std::cin >> config;
    //TODO CONFIGURE QUIZ LEVEL

  }

}

void InterfaceScreen::showQuizPanel() {
  Multilingual *obj = Multilingual::Instance();
  int wordLanguage;
  std::string dutchWord, englishWord;
  Word quiz;

  std::cout << obj->showPhrases("quiz-language") << std::endl;
  std::cin >> wordLanguage;
  if (1 == wordLanguage) {
    std::cout << obj->showPhrases("quiz") + " english" << std::endl;
    std::cin >> englishWord;
    if (englishWord == quiz.meaning) {
      std::cout << obj->showPhrases("correct") << std::endl;
    } else {
      std::cout << obj->showPhrases("wrong") << std::endl;
    }
  } else if (2 == wordLanguage) {
    std::cout << obj->showPhrases("quiz") + " dutch" << std::endl;
    std::cout << dutchWord;
    if (dutchWord == quiz.dutch) {
      std::cout << obj->showPhrases("correct") << std::endl;
      //TODO DECREASE THE PRIORITY
    } else {
      std::cout << obj->showPhrases("wrong") << std::endl;
      //TODO INCREASE THE PRIORITY
    }
  } else {
    std::cout << obj->showPhrases("wrong-input") << std::endl;
  }

}


