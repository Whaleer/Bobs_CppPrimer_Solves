//
// Created by Bingxi L on 2024/4/9.
//
#include <vector>
#include <iostream>

using namespace std;

vector<int>* makeVector(){
    return new vector<int> {};
}

auto populate(vector<int> * vec){
    for(int i; cout << "please enter:\n", cin >>i; vec->push_back(i));
    return vec;
}

auto print(vector<int> * vec) -> ostream&
{
    for(auto i : *vec){
        cout << i << " ";
    }
    return cout;
}

int main(){

    auto vec = populate(makeVector());
    print(vec) << endl;
    delete vec;
    return 0;
}