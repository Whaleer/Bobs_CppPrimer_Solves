//
// Created by Bingxi L on 2024/5/21.
//
#include "14_05.h"

int main()
{
    Book book1(123, "CP5", "Lippman", "2012");
    Book book2(123, "CP5", "Lippman", "2012");

    if (book1 == book2)
        std::cout << book1 << std::endl;
}