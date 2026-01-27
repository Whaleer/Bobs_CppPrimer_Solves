#include <string>
#include <set>

using namespace std;
class Folder;

class Message {
    friend class Folder;
public:
    explicit Message(const string &str = "") : contents(str) {}
    // 拷贝控制成员
    Message(const Message &); // 拷贝构造函数
    Message &operator=(const Message &); // 拷贝赋值运算符
    ~Message(); // 析构函数
    // 从给定 Folder 集合中添加/删除本 Message 指针
    void save(Folder &);
    void remove(Folder &);

private:
    string contents; // 消息文本
    set<Folder *> folders; // 包含本 Message 的 Folder

    // 将本 message 添加到指定参数的 folder 中
    void add_to_folders(const Message &);
    // 从 folders 中的每一个 Folder 中删除本 Message
    void remove_from_Folders();

};

class Folder {
    friend class Message;

public:
    Folder() = default;
    Folder(const Folder &);
    Folder &operator=(const Folder &);
    ~Folder();

private:
    set<Message *> msgs;
    void add_to_Message(const Folder &);
    void remove_from_Message();
    void addMsg(Message *m) { msgs.insert(m); }
    void remMsg(Message *m) { msgs.erase(m); }
};

// 从给定的 Folder 中添加 Message
void Message::save(Folder &f) {
    folders.insert(&f); // 将给定 Folder 添加到我们的 Folder 列表中
    f.addMsg(this);        // 将本 Message 添加到 f 的 Message 集合中
}

void Message::remove(Folder &f) {
    folders.erase(&f);
    f.remMsg(this);
}


void Message::add_to_folders(const Message &m) {
    for(auto f : m.folders)
        f->addMsg(this);
}

Message::Message(const Message &m): contents(m.contents), folders(m.folders) {
    add_to_folders(m);
}

void Message::remove_from_Folders() {
    for(auto f:folders)
        f->remMsg(this);
}

Message::~Message(){
    remove_from_Folders();
}

Message& Message::operator=(const Message &rhs) {
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_folders(rhs);
    return *this;
}