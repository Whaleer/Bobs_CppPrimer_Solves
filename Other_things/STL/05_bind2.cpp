#include <iostream>
#include <functional>
using namespace std;

int sum(int a, int b, int c) {
    return a + b - c;
}

int main() {
    auto sum2 = bind(sum, std::placeholders::_2, 10, std::placeholders::_1);
    cout << sum2(5,3) << endl;
    return 0;
}