//
// Created by Bingxi L on 2024/4/9.
//
#include <iostream>
#include <iomanip>

int main() {
    double number = 3.141592653589793238;
    std::cout << "默认输出: " << number << std::endl;
    std::cout << "小数点后两位: " << std::setprecision(2) << number << std::endl;
    std::cout << "小数点后五位: " << std::setprecision(5) << number << std::endl;
    return 0;
}
