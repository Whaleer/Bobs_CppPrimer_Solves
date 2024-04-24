//
// Created by Bingxi L on 2024/2/21.
//
#include <iostream>
#include <string>

using namespace std;

int main(){

    string rsp;
    do{
        cout << "input two strings: ";
        string str1, str2;
        cin >> str1 >> str2;
        cout << (str1 <= str2 ? str1 : str2) << " is less than the other. " << "\n\n" << "more ? yes or no:";
        cin >> rsp;
    } while (!rsp.empty() && tolower(rsp[0]) == 'y');

    return 0;
}