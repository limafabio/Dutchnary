//
// Created by fabio on 02/05/22.
//

#ifndef DUTCHNARY_WORD_H
#define DUTCHNARY_WORD_H
#include <string>


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

};


#endif //DUTCHNARY_WORD_H
