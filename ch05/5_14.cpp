//
// Created by Bingxi L on 2024/2/20.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

    string cur_str, pre_str, result_str;
    int cur_str_count = 1, max_str_count = 1;

    while(cin >> cur_str){
        if(pre_str == cur_str){
            ++cur_str_count;
            if(cur_str_count > max_str_count){
                max_str_count = cur_str_count;
                result_str = cur_str;
            }
        }
        else {
            cur_str_count = 1;
        }
        pre_str = cur_str;
    }


    if(max_str_count > 1){
        cout << result_str << " repeat " << max_str_count << " times" << endl;
    }else {
        cout << "no word repeat" << endl;
    }

    return 0;
}