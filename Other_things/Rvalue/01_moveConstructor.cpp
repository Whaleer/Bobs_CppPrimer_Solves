#include <iostream>
#include <vector>

using namespace std;

class MyClass {
public:
    vector<int> data;

    MyClass() : data(vector<int>(100, 0)) {
        cout << "Constructed!\n";
    }

    // move constructor
    MyClass(MyClass &&other) noexcept: data(move(other.data)) {
        cout << "Move constructor!\n";
        other.data.clear();
    }
};

int main() {
    MyClass obj1;
    MyClass obj2 = move(obj1); // move constructor is called here (obj1 is moved into obj2)
    cout << "obj1.data.size(): " << obj1.data.size() << endl;
    cout << "obj2.data.size(): " << obj2.data.size() << endl;
    return 0;
}