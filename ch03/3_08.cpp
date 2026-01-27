#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main(){

    string s("Hello World!");
    int i = 0;
    while (i <= s.size() - 1)
    {   
        s[i] = toupper(s[i]);
        i++;
    }

    
    cout << s << endl;
    return 0;
}               