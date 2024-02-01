#include <iostream>
#include <string>
using namespace std;

int main()
{
    string line;

    cout << "Please enter your full name: ";
    getline(cin, line); // 使用getline从cin读取一行到string变量line

    cout << line << endl;

    return 0;
}
