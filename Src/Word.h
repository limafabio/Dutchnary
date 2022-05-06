//
// Created by fabio on 02/05/22.
//

#ifndef DUTCHNARY_WORD_H
#define DUTCHNARY_WORD_H
#include <string>
class Word {
public:
    int id;
    std::string type;
    std::string meaning;
    std::string sound;
    std::string dutch;
    char *picture;

    void setId(const int i);
    void setType(const std::string &t);
    void setMeaning(const std::string &m);
    void setSound(const std::string &s);
    void setDutch(const std::string &d);
    void setPicture(char *p);

    int getId();
    std::string getType();
    std::string getMeaning();
    std::string getSound();
    std::string getDutch();
    char *getPicture();

};

#endif //DUTCHNARY_WORD_H
