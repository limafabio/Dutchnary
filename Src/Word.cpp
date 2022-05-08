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
    int Word::getId() const {
        return id;
    }
    const std::string & Word::getType() const {
        return type;
    }
    const std::string & Word::getMeaning() const {
        return meaning;
    }
    const std::string & Word::getSound() const {
        return sound;
    }
    const std::string & Word::getDutch() const {
        return dutch;
    }
    char * Word::getPicture() const {
        return picture;
    }

    std::string Word::convertToString(){
        std::string stream;
        stream = std::to_string(getId()) + "|" + getType() + "|" + getMeaning() + "|" + getSound() + "|" + getDutch() + "|" + getPicture();
        return stream;
    }

    Word Word::convertToWord(std::string stream) {
        Word obj;
        int index = stream.find("|");
        std::string id = stream.substr(0,index);
        obj.setId(std::stoi(id));
        int index2 = stream.find("|",index);
        obj.setType(stream.substr(index,index2));
        index = index2;
        index2 = stream.find("|",index);
        obj.setMeaning(stream.substr(index,index2));
        index = index2;
        index2 = stream.find("|",index);
        obj.setSound(stream.substr(index,index2));
        index = index2;
        index2 = stream.find("|",index);
        obj.setDutch(stream.substr(index,index2));
        index = index2;
        index2 = stream.find("|",index);

        return obj;
    }

