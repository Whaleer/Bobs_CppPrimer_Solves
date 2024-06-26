//
// Created by Bingxi L on 2024/5/21.
//

#ifndef CPPPRIMER_14_05_H
#define CPPPRIMER_14_05_H

#include <iostream>
#include <string>

class Book {
    friend std::istream &operator>>(std::istream &, Book &);

    friend std::ostream &operator<<(std::ostream &, const Book &);

    friend bool operator==(const Book &, const Book &);

    friend bool operator!=(const Book &, const Book &);

public:
    Book() = default;

    Book(unsigned no, std::string name, std::string author, std::string pubdate) : no_(no), name_(name),
                                                                                   author_(author), pubdate_(pubdate) {}

    Book(std::istream &in) { in >> *this; }


private:
    unsigned no_;
    std::string name_;
    std::string author_;
    std::string pubdate_;
};

std::istream &operator>>(std::istream &, Book &);

std::ostream &operator<<(std::ostream &, const Book &);

bool operator==(const Book &, const Book &);

bool operator!=(const Book &, const Book &);

#endif //CPPPRIMER_14_05_H
