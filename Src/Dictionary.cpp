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
      words.emplace_back(line);
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
      file << word.convertToString() << std::endl;
    }
  }
  file.close();
  return 0;
}

bool Dictionary::wordIsDictionary(std::string dutch) {
  int sizeWord = words.size();
  for (int i = 0; i < sizeWord; i++) {
    if (dutch == words[i].getDutch()) {
      return true;
    }
  }
  return false;
}

Word Dictionary::searchDutchWord(std::string dutch) {
  //TODO create a standard error,
  if (words.empty())
    return {};
  Word wordFound;
  int sizeWords = words.size();
  for (int i = 0; i < sizeWords; i++) {
    Word currentWord;
    if (currentWord.getDutch() == dutch) {
      wordFound = currentWord;
      break;
    }
  }
  return wordFound;
}
bool Dictionary::insertWord(Word wordToInsert) {

  Dictionary *dict = Dictionary::Instance();
  dict->words.emplace_back(wordToInsert);
  return true;

}



