//
// Created by fabio on 05/05/22.
//

#ifndef DUTCHNARY_DICTIONARY_H
#define DUTCHNARY_DICTIONARY_H
#include<vector>
#include"Word.h"

class Dictionary {

public:

  static Dictionary *Instance();

  void readWords();
  bool insertWord(Word wordToInsert);
  int writeWords();
  Word searchDutchWord(std::string dutch);
  bool wordIsDictionary(std::string dutch);

private:
  std::vector<Word> words;

};

#endif //DUTCHNARY_DICTIONARY_H
