#include <iostream>
#include <string>

using namespace std;

inline bool is_shorter(const string &lht, const string &rht) {
    return lht.size() < rht.size();
}

int main() {

    cout << is_shorter("pezy", "mooophy") << endl;

    return 0;
}