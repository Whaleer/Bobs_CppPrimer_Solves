//
// Created by Bingxi L on 2024/4/15.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void elimDups(vector<string> & words){
    // 按字典序排序，以便查找重复单词
    sort(words.begin(), words.end());

    // unique 重排序输入范围，使得每一个单词只出现一次
    // unique 并不是真的删除元素，而是覆盖相邻的重复的元素，使得不重复的元素出现在序列开始部分
    // unique 返回的迭代器指向最后一个不重复元素之后的位置
    auto end_unique = unique(words.begin(), words.end());
    // 使用 erase 删除重复单词
    words.erase(end_unique, words.end());
}

int main() {

    vector<string> vec = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(vec);

    for(auto i : vec)
        cout << i << " ";
    cout << endl;

    return 0;
}