//
// Created by Bingxi L on 2024/4/27.
//
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

auto make_family() {
    map<string, vector<string>> fam;
    for (string str; cout << "last name:\n", cin >> str && str != "@q";)
        for (string kid; cout << "kid name:\n", cin >> kid && kid != "@q";)
            fam[str].push_back(kid);
    return fam;
}


auto print_fam(map<string, vector<string>> const &fam){
    for(auto i : fam){
        cout << i.first << ": {";
        for(auto kid: i.second)
            cout << kid << ", ";
        cout << "}" << endl;
    }
}

int main() {
    print_fam(make_family());
    return 0;
}