#include <iostream>
#include <Word.h>
int main() {
    Word first, second;
    first.setMeaning("hello");
    first.setDutch("hallo");
    second.setMeaning("world");
    second.setDutch("wereld");

    std::cout << first.getDutch() << " " << second.getDutch()  << std::endl;
    std::cout << first.getMeaning() << " " << second.getMeaning()  << std::endl;


    return 0;
}
