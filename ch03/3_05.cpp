#include<iostream>
#include<string>

using namespace std;


int main(){

    string s;
    for(string buffer; cin >> buffer; s = s + " " + buffer);
    cout << "the concatenated string is : " << s << endl;

    
    return 0;
}