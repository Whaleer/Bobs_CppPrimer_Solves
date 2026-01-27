//
// Created by Bingxi L on 2024/5/21.
//
#include <iostream>
#include <sstream>
#include "14_02.h"

using namespace std;

int main() {
    // 模拟输入数据
    string input_data = "12345 10 15.99";
    istringstream iss(input_data);

    // 使用输入流构造Sales_data对象
    Sales_data sd(iss);

    // 输出结果以验证对象是否正确初始化
    cout << "ISBN: " << sd.isbn() << endl;
    // 此处假设有一个函数来获取units_sold和revenue，为了完整性我们应该假设这样的函数存在
    // 假设函数 get_units_sold() 和 get_revenue() 存在
    // cout << "Units sold: " << sd.get_units_sold() << endl;
    // cout << "Revenue: " << sd.get_revenue() << endl;

    return 0;
}
