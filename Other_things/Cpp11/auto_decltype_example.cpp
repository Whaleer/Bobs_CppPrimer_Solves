#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <typeinfo>

// 用于展示decltype和auto的示例代码
int main() {
    // ===== auto的基本用法 =====
    // 1. 基本类型推导
    auto i = 42;           // i是int类型
    auto d = 3.14;         // d是double类型
    auto s = "hello";      // s是const char*类型
    auto str = std::string("hello"); // str是std::string类型
    
    std::cout << "=== auto基本用法 ===" << std::endl;
    std::cout << "i: " << i << ", 类型: " << typeid(i).name() << std::endl;
    std::cout << "d: " << d << ", 类型: " << typeid(d).name() << std::endl;
    std::cout << "s: " << s << ", 类型: " << typeid(s).name() << std::endl;
    std::cout << "str: " << str << ", 类型: " << typeid(str).name() << std::endl;
    
    // 2. 复杂类型推导
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto it = vec.begin(); // it是std::vector<int>::iterator类型
    
    std::map<std::string, int> map = {{"one", 1}, {"two", 2}};
    auto map_it = map.begin(); // map_it是std::map<std::string, int>::iterator类型
    
    // 3. auto与引用和const结合
    int x = 10;
    auto& rx = x;          // rx是int&类型
    const auto& crx = x;   // crx是const int&类型
    
    rx = 20;               // 可以修改x的值
    // crx = 30;           // 错误：crx是const引用，不能修改
    
    std::cout << "\n=== auto与引用和const ===" << std::endl;
    std::cout << "x: " << x << std::endl;
    std::cout << "rx: " << rx << std::endl;
    std::cout << "crx: " << crx << std::endl;
    
    // ===== decltype的基本用法 =====
    std::cout << "\n=== decltype基本用法 ===" << std::endl;
    
    // 1. 基本类型推导
    int a = 10;
    decltype(a) b = 20;        // b是int类型
    decltype(3.14) c = 3.14;   // c是double类型
    
    std::cout << "b: " << b << ", 类型: " << typeid(b).name() << std::endl;
    std::cout << "c: " << c << ", 类型: " << typeid(c).name() << std::endl;
    
    // 2. decltype与表达式
    int n = 0;
    int m = 0;
    decltype(n + m) sum = n + m;  // sum是int类型
    decltype(n = m) ref = n;      // ref是int&类型，因为赋值表达式返回左值引用
    
    ref = 100;  // 修改ref也会修改n
    std::cout << "n: " << n << ", ref: " << ref << std::endl;
    
    // 3. decltype与函数返回值
    auto func = [](int x) -> int { return x * 2; };
    decltype(func(10)) result = func(5);  // result是int类型
    std::cout << "result: " << result << std::endl;
    
    // 4. decltype((变量))的特殊规则
    int val = 42;
    decltype(val) val1 = val;     // val1是int类型
    decltype((val)) val2 = val;   // val2是int&类型，因为(val)是一个表达式，产生左值引用
    
    val2 = 100;  // 修改val2也会修改val
    std::cout << "val: " << val << ", val1: " << val1 << ", val2: " << val2 << std::endl;
    
    // ===== auto和decltype的区别和应用 =====
    std::cout << "\n=== auto和decltype的区别和应用 ===" << std::endl;
    
    // 1. 函数模板中使用decltype推导返回类型
    auto add = [](auto x, auto y) -> decltype(x + y) {
        return x + y;
    };
    
    auto sum1 = add(5, 3);        // sum1是int类型
    auto sum2 = add(3.5, 2.5);    // sum2是double类型
    
    std::cout << "sum1: " << sum1 << ", 类型: " << typeid(sum1).name() << std::endl;
    std::cout << "sum2: " << sum2 << ", 类型: " << typeid(sum2).name() << std::endl;
    
    // 2. C++14中的decltype(auto)
    int num = 42;
    decltype(auto) num_ref = (num);  // num_ref是int&类型
    
    num_ref = 100;
    std::cout << "num: " << num << ", num_ref: " << num_ref << std::endl;
    
    return 0;
}
