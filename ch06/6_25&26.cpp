#include "iostream"
#include "string"

using namespace std;
int main(int argc, char *argv[]){

    string str;
    cout << argc << endl;
    for (int i = 1; i != argc; ++i) {
        str += string(argv[i])+ " ";
    }

    cout << str << endl;
    return 0;
}

