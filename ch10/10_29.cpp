//
// Created by Bingxi L on 2024/4/25.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

int main() {

    ifstream ifs("./book.txt");
    istream_iterator<string> in(ifs), eof;
    vector<string> vec;
    copy(in, eof, back_inserter(vec));

    copy(vec.begin(), vec.end(), ostream_iterator<string>(cout, "\n"));
    return 0;
}