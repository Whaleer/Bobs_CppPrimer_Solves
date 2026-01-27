// 科大讯飞
// 01.矩阵转置差值
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int matrix[500][500];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans += abs(matrix[i][j] - matrix[j][i]);
        }
    }

    cout << ans << endl;
    return 0;
}

