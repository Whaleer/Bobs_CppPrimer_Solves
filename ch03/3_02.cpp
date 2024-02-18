#include<iostream>
#include<string>

using namespace std;


int main(){

    for(string str; getline(cin, str); cout << str << endl);
    return 0;
}