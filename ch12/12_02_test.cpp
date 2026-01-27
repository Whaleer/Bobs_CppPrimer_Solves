#include "12_02.h"
#include <iostream>

using namespace std;
int main() {
    StrBlob sb1{"hello", "world", "pezy"};
    StrBlob sb2(sb1);
    StrBlob sb3{"hello", "world", "pezy"};

    cout << sb1.use_Count() << endl;
    cout << sb2.use_Count() << endl;
    cout << sb3.use_Count() << endl;

    cout << sb1.front() << " " << sb1.back() << endl;
    sb1.pop_back();
    cout << sb1.front() << " " << sb1.back() << endl;
    cout << sb2.front() << " " << sb2.back() << endl;
    cout << sb3.front() << " " << sb3.back() << endl;

//    cout << sb1.front() << " " << sb1.back() << endl;
//    sb1.back() = "dude";
//    cout << sb1.front() << " " << sb1.back() << endl;
//    cout << sb2.front() << " " << sb2.back() << endl;

}