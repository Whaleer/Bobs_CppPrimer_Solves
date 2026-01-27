//
// Created by Bingxi L on 2024/4/15.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


/*
 * 实现 biggies
 * 1. 现将 string 类型的 vector 中删除重复的单词
 * 2. 将单词按照长度排序，长度相同的按照字典序排序
 * 3. 获取一个迭代器，指向第一个size() >= sz 的元素
 * 4. 计算满足 size >= sz 的元素
 * 5. 打印长度 >= sz 的单词，每个单词后接一个空格
 */
string make_plural(size_t ctr, const string &word, const string &ending) {
    return (ctr > 1) ? word + ending : word;
}

void elimDups(vector<string> &vec) {
    sort(vec.begin(), vec.end());
    auto end_unique = unique(vec.begin(), vec.end());
    vec.erase(end_unique, vec.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz) {

    // 消除重复元素
    elimDups(words);

    // 按长度排序
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b) { return a.size() < b.size(); });

    // 找到第一个满足 size >= sz 的元素
    auto wc = find_if(words.begin(), words.end(), [sz](const string &s) { return s.size() >= sz; });

    // 计算满足 size >= sz 的元素数目
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;

    // 打印长度 >= sz 的单词
    for_each(wc, words.end(), [](const string &s) { cout << s << " "; });

}

int main() {

    vector<string> words = {"asd", "qweqwew", "zx", "asdasdadas", "q", "sadgd", "qwejyyyyj"};
    biggies(words, 5);

    return 0;
}