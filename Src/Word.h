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

  void setId(int i);
  void setType(const std::string &t);
  void setMeaning(const std::string &m);
  void setSound(const std::string &s);
  void setDutch(const std::string &d);
  void setPicture(char *p);

  int getId() const;
  const std::string &getType() const;
  const std::string &getMeaning() const;
  const std::string &getSound() const;
  const std::string &getDutch() const;
  char *getPicture() const;

  std::string convertToString();
  Word(std::string stream);
  Word();

};

#endif //DUTCHNARY_WORD_H
