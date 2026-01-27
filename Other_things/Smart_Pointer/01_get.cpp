#include <iostream>
#include <memory>

void useRawPointer(int* p) {
    if (p) {
        std::cout << "Value: " << *p << "\n";
    }
}

int main() {
    std::unique_ptr<int> ptr = std::make_unique<int>(42);
    int* rawPtr = ptr.get(); // 获取原生指针，但不转移所有权

    useRawPointer(rawPtr); // 使用原生指针进行一些操作

    // 依然可以通过 ptr 访问资源，因为所有权没有转移
    std::cout << "Value from unique_ptr: " << *ptr << "\n";

    return 0;
}