//
// Created by Bingxi L on 2024/2/12.
//
#include <iostream>
#include <string>

using namespace std;
int main(){

    string s1 = "Mooophy";
    string s2 = "Pezy";
    if(s1 == s2){
        cout << "s1 and s2 is same" << endl;
    }else if(s1 > s2){
        cout << "Mooophy > Pezy" << endl;
    }else{
        cout << "Mooophy < Pezy" << endl;
    }


    cout << "=================" << endl;

    const char * cs1 = "Wangyue";
    const char * cs2 = "Pezy";
    auto result = strcmp(cs1,cs2);
    if(result == 0){
        cout << "same string" << endl;
    }else if(result < 0){
        cout << "Wangyue < Pezy" << endl;
    }else{
        cout << "Wangyue > Pezy" << endl;
    }


    return 0;
}