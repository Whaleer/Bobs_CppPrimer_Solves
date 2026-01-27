//
// Created by Bingxi L on 2024/2/20.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};

    int grade = 0;
    while(cin >> grade){
        string letterGrade = grade < 60 ? scores[0] : scores[(grade - 50) / 10];
        letterGrade += (grade == 100 || grade < 60) ? "" : (grade % 10 > 7) ? "+" : (grade % 10 < 3) ? "-" : "";
        cout << letterGrade << endl;
    }

    return 0;
}