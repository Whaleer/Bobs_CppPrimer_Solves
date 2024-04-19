//
// Created by Bingxi L on 2024/4/16.
//
#include <iostream>
#include <thread>

using namespace std;

int main(){
    unsigned concurrent_count = thread::hardware_concurrency();
    cout << "hardware_concurrency: " << concurrent_count << endl;
}
