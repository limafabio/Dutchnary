//
// Created by fabio on 02/05/22.
//

#include "Word.h"
#include <string>

    //Word::setter
    void Word::setId(const int i) {
        id = i;
    }
    void Word::setType(const std::string &t) {
        type = t;
    }
    void Word::setMeaning(const std::string &m) {
        meaning = m;
    }
    void Word::setSound(const std::string &s) {
        sound = s;
    }
    void Word::setDutch(const std::string &d) {
        dutch = d;
    }
    void Word::setPicture(char *p) {
        picture = p;
    }

    //Getter
    int Word::getId() {
        return id;
    }
    std::string Word::getType() {
        return type;
    }
    std::string Word::getMeaning() {
        return meaning;
    }
    std::string Word::getSound() {
        return sound;
    }
    std::string Word::getDutch() {
        return dutch;
    }
    char * Word::getPicture() {
        return picture;
    }
