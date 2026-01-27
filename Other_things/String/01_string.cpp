//
// Created by Bingxi L on 2024/5/17.
//
#include<string.h>

class String {

public:
    String(const char *str = nullptr);

    String(const String &other);

    ~String();

    String &operator=(const String &other);

private:
    char *m_data;
};

// 构造函数
String::String(const char *str) {
    if (str == nullptr) {
        m_data = new char[1]; // 对空字符串自动申请存放结束标志'\0'
        *m_data = '\0';
    } else {
        int length = strlen(str);
        m_data = new char[length + 1];
        strcpy(m_data, str);
    }
}

// 析构函数
String::~String() {
    delete[] m_data;
}

// 拷贝构造函数
String::String(const String& other) {
    int length = strlen(other.m_data);
    m_data = new char[length + 1];
    strcpy(m_data, other.m_data);
}

// 赋值函数
String& String::operator=(const String &other) {
    if(this == &other){
        return *this;
    }
    delete[] m_data;
    int length = strlen(other.m_data);
    m_data = new char[length + 1];
    strcpy(m_data, other.m_data);
    return *this;
}
