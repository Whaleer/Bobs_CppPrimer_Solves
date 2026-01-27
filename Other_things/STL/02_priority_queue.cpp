#include <iostream>
#include <queue>
#include <vector>
#include <functional>

int main() {
    std::priority_queue<int, std::vector<int>, std::greater<>> minHeap;
    minHeap.push(10);
    minHeap.push(30);
    minHeap.push(20);

    while (!minHeap.empty()) {
        std::cout << minHeap.top() << " ";
        minHeap.pop();
    }
    return 0;
}