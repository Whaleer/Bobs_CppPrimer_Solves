//
// Created by Bingxi L on 2024/4/19.
//
#include <iostream>
#include <string>
#include <list>

using namespace std;


int main(){


    list<string> li;
    for(string str; cin >> str; li.push_back(str));
    for(auto iter = li.begin(); iter != li.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}

