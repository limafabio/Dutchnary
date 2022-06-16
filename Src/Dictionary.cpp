//
// Created by fabio on 05/05/22.
//

#include<fstream>
#include "Dictionary.h"
#include "Word.h"

Dictionary *Dictionary::Instance() {
  static Dictionary singleton;
  return &singleton;
}

void Dictionary::readWords() {
  std::string location_file = DataBase;
  std::ifstream file(location_file);

  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
      Word newWord(line);
      words.emplace_back(newWord);
    }
    file.close();
  }
}

int Dictionary::writeWords() {

  std::string location_file = DataBase;
  std::fstream file;
  file.open(location_file, std::ios::out);
  for (auto &word : words) {
    if (file.is_open()) {
      if (word.getDutch() != "") {
        file << word.convertToString() << std::endl;
      }
    }
  }
  file.close();
  return 0;
}

bool Dictionary::dutchWordIsDictionary(std::string dutch) {
  int sizeWord = words.size();
  for (int i = 0; i < sizeWord; i++) {
    if (dutch == words[i].getDutch()) {
      return true;
    }
  }
  return false;
}

bool Dictionary::englishWordIsDictionary(std::string english) {
  int sizeWord = words.size();
  for (int i = 0; i < sizeWord; i++) {
    if (english == words[i].getMeaning()) {
      return true;
    }
  }
  return false;
}

int Dictionary::searchEnglishWord(std::string english) {

  int indexWord = 0;
  int sizeWords = words.size();
  for (int i = 0; i < sizeWords; i++) {
    if (words[i].getMeaning() == english) {
      indexWord = i;
      break;
    }
  }
  return indexWord;

}

int Dictionary::searchDutchWord(std::string dutch) {
  //TODO create a standard error,
  int indexWord = 0;
  int sizeWords = words.size();
  for (int i = 0; i < sizeWords; i++) {
    if (words[i].getDutch() == dutch) {
      indexWord = i;
      break;
    }
  }
  return indexWord;
}

bool Dictionary::insertWord(Word wordToInsert) {

  Dictionary *dict = Dictionary::Instance();
  dict->words.emplace_back(wordToInsert);
  return true;

}

bool Dictionary::updateWord(Word wordToUpdate, int index) {

  Dictionary *dict = Dictionary::Instance();
  dict->words[index].setDutch(wordToUpdate.getDutch());
  dict->words[index].setMeaning(wordToUpdate.getMeaning());
  dict->words[index].setSound(wordToUpdate.getSound());
  dict->words[index].setType(wordToUpdate.getType());
  dict->words[index].setPriority(wordToUpdate.getPriority());
  return true;

}

bool Dictionary::deleteWord(int index) {
  Dictionary *dict = Dictionary::Instance();
  dict->words[index].setDutch("");
  dict->words[index].setMeaning("");
  dict->words[index].setSound("");
  dict->words[index].setType("");
  dict->words[index].setPriority(0);
  return true;
}



