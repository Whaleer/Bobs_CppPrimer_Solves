#include <iostream>
#include <algorithm>
#include <vector>

bool customCompare(int a, int b) {
    return a > b; // 降序比较
}

int main() {
    std::vector<int> v = {8, 6, 5, 4, 4, 2, 1};

    int value = 4;
    auto it = std::upper_bound(v.begin(), v.end(), value, customCompare);

    if (it != v.end()) {
        std::cout << "The first element greater than " << value << " is " << *it << " at index " << std::distance(v.begin(), it) << std::endl;
    } else {
        std::cout << "No element greater than " << value << " found." << std::endl;
    }

    return 0;
}