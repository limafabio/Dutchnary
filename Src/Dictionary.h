//
// Created by fabio on 05/05/22.
//

#ifndef DUTCHNARY_DICTIONARY_H
#define DUTCHNARY_DICTIONARY_H
#include<vector>
#include"Word.h"

class Dictionary {

public:
    std::vector<Word> words;

    std::vector<Word> readWords();
    int writeWords(std::vector<Word>);
    Word searchDutchWord(std::string dutch);

};


#endif //DUTCHNARY_DICTIONARY_H
