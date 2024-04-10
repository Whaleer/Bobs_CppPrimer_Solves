//
// Created by Bingxi L on 2024/3/28.
//
#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <exception>
#include <stdexcept>

using namespace std;

class StrBlob {
private:
    /*
     * 每一个 StrBlob 类都设置了一个 shared_ptr 来管理动态分配的 vector
     * 这个 shared_ptr 的成员会记录有多少个 StrBlob 共享相同的 vector
     * 并在 vector 的最后一个使用者被销毁时释放 vector
    */
    using size_type = vector<string>::size_type;
    shared_ptr<vector<string> > data;

    void check(size_type i, const string &msg) const {
        if (i >= data->size()) throw out_of_range(msg);
    }

public:

    StrBlob() : data(std::make_shared<vector<string> >()) {}

    StrBlob(initializer_list <string> il) : data(make_shared<vector<string> >(il)) {}

    size_type size() const { return data->size(); }

    bool empty() const { return data->empty(); }

    void push_back(const string &t) { data->push_back(t); }

    void pop_back() {
        check(0, "pop_back on empty StrBlob");
        data->pop_back();
    }

    string &front() {
        check(0, "front on empty StrBlob");
        return data->front();
    }

    string &back() {
        check(0, "back on empty StrBlob");
        return data->back();
    }

    const std::string &front() const {
        check(0, "front on empty StrBlob");
        return data->front();
    }

    const std::string &back() const {
        check(0, "back on empty StrBlob");
        return data->back();
    }
};


