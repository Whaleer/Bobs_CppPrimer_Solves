//
// Created by Bingxi L on 2024/4/17.
//

#ifndef CPPPRIMER_13_34_36_37_H
#define CPPPRIMER_13_34_36_37_H

#include <string>
#include <set>

using namespace std;

class Folder;

class Message {
    friend class Folder;

    friend void swap(Message &, Message &);

public:
    // 将构造函数声明为 explicit 防止了构造函数参与隐式类型转换，即自动将一个类型转换为另一个类型
    // 表明构造函数仅用于直接初始化，不应被用于隐式转换。
    explicit Message(const string &str = "") : contents(str) {}

    Message(const Message &); // 拷贝构造函数
    Message &operator=(const Message &); // 拷贝赋值运算符
    ~Message(); // 析构函数

    // 从给定 Folder 集合中添加/删除本 Message
    void save(Folder &);

    void remove(Folder &);

private:
    string contents; // 实际消息文本
    set<Folder *> folders; // 包含本 message 的 folder

    // 拷贝构造函数、拷贝赋值运算符、析构函数所使用的工具函数
    // 将本 message 添加到指向参数的 Folder 中
    void add_to_Folders(const Message &);

    // 从 folders 中的每个 Folder 中删除本 Message
    void remove_from_Folders();
};

void swap(Message &, Message &);

class Folder {
    friend void swap(Folder &, Folder &);

    friend class Message;

public:
    Folder() = default;

    Folder(const Folder &);

    Folder &operator=(const Folder &);

    ~Folder();

    void print_debug();
    
private:
    set<Message *> msgs;

    void add_to_Message(const Folder &);

    void remove_from_Message();

    void addMsg(Message *m) { msgs.insert(m); }

    void remMsg(Message *m) { msgs.erase(m); }
};

void swap(Folder &, Folder &);


#endif //CPPPRIMER_13_34_36_37_H
