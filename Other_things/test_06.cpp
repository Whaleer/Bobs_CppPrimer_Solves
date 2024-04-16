//
// Created by Bingxi L on 2024/4/10.
//
#include <iostream>

using namespace std;

int fun(int num)
{
    int cnt = 0;
    while (num){
        cnt++;
        num = num&(num-1);
        cout << num << endl;
    }
    return cnt;
}

int main(){
    
    printf("%d\n",fun(22));
    return 0;
}