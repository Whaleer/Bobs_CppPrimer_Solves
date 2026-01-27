//
// Created by Bingxi L on 2024/4/10.
//
#include <iostream>
#include <cstring>

int main(){

    const char * str1 = " 3.14";
    const char * str2 = " 3.278";

    int result = strcmp(str1, str2);

    if (result == 0) {
        std::cout << "Strings are equal" << std::endl;
    } else if (result < 0) {
        std::cout << "str1 is less than str2" << std::endl;
    } else {
        std::cout << "str1 is greater than str2" << std::endl;
    }
    return 0;
}