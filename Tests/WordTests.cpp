#include <Catch2/Catch.hpp>
#include<Word.h>


TEST_CASE("create_word", "[create]") {
    Word word_test;
    word_test.setId(1);
    word_test.setDutch("vrouw");
    word_test.setSound("vrouw");
    word_test.setMeaning("woman");
    word_test.setType("substantive");

    REQUIRE(word_test.getId() == 1);
    REQUIRE(word_test.getDutch() == "vrouw");
    REQUIRE(word_test.getSound() == "vrouw");
    REQUIRE(word_test.getMeaning() == "woman");
    REQUIRE(word_test.getType() == "substantive");

}