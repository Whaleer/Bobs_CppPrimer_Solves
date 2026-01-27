#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main(){

  
    for(string s; getline(cin, s); cout << endl)
        for(auto i : s)
            if(!ispunct(i))
                cout << i;
    return 0;
}               