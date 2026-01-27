//
// Created by Bingxi L on 2024/2/21.
//
#include "iostream"
#include "string"

using namespace std;

int main(){
    string read, pre;
    while(cin >> read)
        if(read == pre)
            break;
        else
            pre = read;

    if(cin.eof())
        cout << "no word was repeated." << endl;
    else
        cout << read << " occers twice in succession." << endl;

    return 0;
}