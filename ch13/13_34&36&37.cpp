//
// Created by Bingxi L on 2024/4/17.
//
#include <string>
#include <set>
#include <iostream>

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

void swap(Message &lhs, Message &rhs) {
    using std::swap;
    lhs.remove_from_Folders(); // Use existing member function to avoid duplicate code.
    rhs.remove_from_Folders(); // Use existing member function to avoid duplicate code.

    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);

    lhs.add_to_Folders(lhs); // Use existing member function to avoid duplicate code.
    rhs.add_to_Folders(rhs); // Use existing member function to avoid duplicate code.
}

void Message::save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f) {
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m) {
    for (auto f: m.folders)
        f->addMsg(this);
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
    add_to_Folders(m);
}

void Message::remove_from_Folders() {
    for (auto f: folders)
        f->remMsg(this);
}

Message::~Message() {
    remove_from_Folders();
}


Message &Message::operator=(const Message &rhs) {
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}


