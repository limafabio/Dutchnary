//
// Created by fabio on 05/05/22.
//

#include<fstream>
#include "Dictionary.h"
#include "Word.h"


    std::vector<Word> Dictionary::readWords(){
        std::string location_file = DataBase;
        std::ifstream file(location_file);
        if(file.is_open())
        {
            std::string line;
            while(std::getline(file,line)){
                //TODO convert lines in object word
                printf("%s", line.c_str());
            }
            file.close();
        }
        return words;
    }



    int Dictionary::writeWords(std::vector<Word> words){

        std::string location_file = DataBase;
        std::fstream file;
        file.open(location_file,std::ios_base::app);
       //TODO convert word in line, search a method to salve in format that can export to database



        return 0;
    }


    Word Dictionary::searchDutchWord(std::string dutch){
        //TODO create a standard error
        if (words.empty())
            return {};
        Word wordFound;
        int sizeWords = words.size();
        for(int i = 0; i < sizeWords; i++){
            Word currentWord;
            if (currentWord.getDutch() == dutch){
                wordFound = currentWord;
                break;
            }
        }
        return wordFound;
    }


