//
// Created by Bingxi L on 2024/2/12.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {

    int arr[3][4] = {
            {0, 1, 2,  3},
            {4, 5, 6,  7},
            {8, 9, 10, 11},
    };


    // 1
    for(const int(&row)[4] : arr){
        for(int col : row){
            cout << col << " ";
        }
    }
    cout << endl;

    // 2
    for(size_t i = 0; i != 3; i++){
        for(size_t j = 0; j != 4; j++){
            cout << arr[i][j] << " ";
        }
    }
    cout << endl;

    // 3
    for (int(*row)[4] = arr; row != arr + 3; ++row)
        for (int *col = *row; col != *row + 4; ++col) cout << *col << " ";
    cout << endl;

    return 0;
}