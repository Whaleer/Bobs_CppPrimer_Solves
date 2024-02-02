//
// Created by Bingxi L on 2024/2/2.
//
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int main() {


    vector<string> s;
    for(string buffer; cin >> buffer; s.push_back(buffer));

    for(auto &i : s){
        for (int j = 0; j < i.size(); ++j) {
            i[j] = toupper(i[j]);
        }
    }

    for(string::size_type i = 0; i != s.size(); ++i){
        if(i != 0 && i % 8 == 0) cout << endl;
        cout << s[i] << " ";
    }
    cout << endl;

    return 0;
}