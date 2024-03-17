#include "iostream"
#include "string"

using namespace std;

bool any_Capital(string const &str) {
    for (auto ch: str) {
        if (isupper(ch)) return true;
    }
    return false;
}

void to_lowercase(string &str) {
    for (auto &ch: str) ch = tolower(ch);
}

int main() {

    string hello("Hello world");
    cout << any_Capital(hello) << endl;
    to_lowercase(hello);
    cout << hello << endl;
    return 0;
}