#include <iostream>
#include <string>
using namespace std;

int sum()
{
    int sum = 0;
    int i = 50;
    while (i <= 100)
    {
        sum += i;
        i++;
    }
    return sum;
}

void checkString(string str1, string str2){

    if(str1.size() == str2.size(  )){
        cout << "The two strings have the same length." << endl;
    }else {
        cout << "The longer string is " << ((str1.size() > str2.size()) ? str1 : str2) << endl;
    }
}

int main()
{
    string str1;
    cin >> str1;
    string str2;
    cin >> str2;


    cout << "question 1 : " << sum() << endl;
    cout << "question 2 : ";
    checkString(str1, str2);
    return 0;
}