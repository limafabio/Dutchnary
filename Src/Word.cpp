//
// Created by fabio on 02/05/22.
//

#include "Word.h"
#include <string>

//Word::setter
void Word::setId(const int i) {
  id = i;
}
void Word::setPriority(int i) {
  priority = i;
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
int Word::getPriority() const {
  return priority;
}
const std::string &Word::getType() const {
  return type;
}
const std::string &Word::getMeaning() const {
  return meaning;
}
const std::string &Word::getSound() const {
  return sound;
}
const std::string &Word::getDutch() const {
  return dutch;
}
char *Word::getPicture() const {
  return picture;
}

std::string Word::convertToString() {

  //TODO CONFIGURE PICTURE
  std::string stream;
  stream =
      std::to_string(this->getId()) + "|" + this->getType() + "|" + this->getMeaning() + "|" + this->getSound() + "|"
          + this->getDutch() + "|" + std::to_string(this->getPriority());
  return stream;

}

Word::Word(std::string stream) {

  int index = stream.find("|");
  std::string id = stream.substr(0, index);
  setId(std::stoi(id));
  index = stream.find("|");

  int index2 = stream.find("|", index + 1);
  std::string type = stream.substr((index + 1), (index2 - index - 1));
  setType(type);

  index = index2 + 1;
  index2 = stream.find("|", index + 1);
  std::string meaning = stream.substr(index, (index2 - index));
  setMeaning(meaning);

  index = index2 + 1;
  index2 = stream.find("|", index + 1);
  std::string sound = stream.substr(index, (index2 - index));
  setSound(sound);

  index = index2 + 1;
  index2 = stream.find("|", index + 1);
  std::string dutch = stream.substr(index, (index2 - index));
  setDutch(dutch);

  index = index2 + 1;
  index2 = stream.find("|", index + 1);
  std::string priority = stream.substr(index, (index2 - index));
  setPriority(std::stoi(priority));
  //TODO SET PICTURE

}
void Word::toLowerWord() {

  std::for_each(meaning.begin(), meaning.end(), [](char &c) {
    c = ::tolower(c);
  });
  std::for_each(dutch.begin(), dutch.end(), [](char &c) {
    c = ::tolower(c);
  });
  std::for_each(sound.begin(), sound.end(), [](char &c) {
    c = ::tolower(c);
  });
  std::for_each(type.begin(), type.end(), [](char &c) {
    c = ::tolower(c);
  });

}
Word::Word() = default;



