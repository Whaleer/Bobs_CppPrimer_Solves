#include <iostream>
#include <string>

int main() {
    int i = 10;
    const int ci = 42;
    std::string s = "hello";

    // 1) decltype(变量名)：直接得到变量的类型
    decltype(i) a = 1;     // a 是 int
    decltype(ci) b = 2;    // b 是 const int
    decltype(s) t = "hi";  // t 是 std::string

    // 2) decltype((变量名))：注意多了一对括号 -> 变成表达式
    //    对于左值表达式，decltype((x)) 推导为 T&（引用）
    decltype((i)) ref_i = i;  // ref_i 是 int&
    ref_i = 99;               // 修改引用会影响原变量

    // 3) decltype(表达式)：根据表达式推导类型
    decltype(i + ci) sum = i + ci;  // sum 是 int
    decltype(s[0]) ch = s[0];       // s[0] 是左值，所以 ch 是 char&
    ch = 'H';                       // 修改 ch 会影响字符串

    std::cout << "i = " << i << "\n";
    std::cout << "a = " << a << ", b = " << b << "\n";
    std::cout << "sum = " << sum << ", s = " << s << "\n";
    return 0;
}
