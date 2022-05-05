//
// Created by fabio on 02/05/22.
//

#ifndef DUTCHNARY_WORD_H
#define DUTCHNARY_WORD_H
#include <string>
#include <fstream>


class Word {
    std::string type;
    std::string meaning;
    std::string sound;
    std::string dutch;
    char * picture;

public:
    //Setter
    void setType(const std::string & t) {
        type = t;
    }
    void setMeaning(const std::string & m){
        meaning = m;
    }

    void setSound(const std::string & s){
        sound = s;
    }

    void setDutch(const std::string &d){
        dutch = d;
    }

    void setPicture(char * p){
        picture = p;
    }

    //Getter
    std::string getType(){
        return type;
    }

    std::string getMeaning(){
        return meaning;
    }

    std::string getSound(){
        return sound;
    }

    std::string  getDutch(){
        return dutch;
    }

    char * getPicture(){
        return picture;
    }

    int readWord(std::string word){

        std::string location_file = DataBase;
        std::ifstream file(location_file);
        if(file.is_open())
        {
            std::string line;
            while(std::getline(file,line)){
                printf("%s", line.c_str());
            }
            file.close();
        }
    return 0;
    }

    int writeWord(std::string word){
        std::string location_file = DataBase;
        std::fstream file;
        file.open(location_file,std::ios_base::app);
        if (file.is_open())
            file.write(word.data(),word.size());
        return 0;
    }

    bool isEqualWord(std::string word1, std::string word2){
        if (word1 == word2)
            return true;
        else
            return false;

    }

    int searchWord(std::string word){
        std::string location_file = DataBase;
        std::ifstream file(location_file);
        if(file.is_open())
        {
            std::string line;
            while(std::getline(file,line)){
                if (isEqualWorld(line,word)){
                  return 0;
                }
                printf("%s", line.c_str());
            }
            file.close();
        }
        return -1;
    }
};


#endif //DUTCHNARY_WORD_H
