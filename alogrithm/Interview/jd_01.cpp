//
// Created by Bingxi L on 2024/8/15.
//
#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;

    int x = 0, y = 0;
    char direction = 'N';

    for (char c : S) {
        if (c == 'W') {
            if (direction == 'N') y++;
            else if (direction == 'E') x++;
            else if (direction == 'S') y--;
            else if (direction == 'W') x--;
        } else if (c == 'A') {
            if (direction == 'N') direction = 'W';
            else if (direction == 'W') direction = 'S';
            else if (direction == 'S') direction = 'E';
            else if (direction == 'E') direction = 'N';
        } else if (c == 'D') {
            if (direction == 'N') direction = 'E';
            else if (direction == 'E') direction = 'S';
            else if (direction == 'S') direction = 'W';
            else if (direction == 'W') direction = 'N';
        }

    }

    cout << x << " " << y << endl;

    return 0;
}