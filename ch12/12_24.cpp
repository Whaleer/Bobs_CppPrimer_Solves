#include <iostream>

using namespace std;

int main(){

    cout << "how long do you want the string?";
    int size;
    cin >> size;
    char *input = new char[size + 1]();
    cin.ignore(); // 忽略前面cin >> size;读取时留下的换行符
    cout << "input the string: ";
    cin.get(input,size+1);
    cout << input;
    delete[] input;

    return 0;
}