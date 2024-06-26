//
// Created by Bingxi L on 2024/4/15.
//
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main() {

    list<int> ilst(5, 4);
    vector<int> ivc(5, 5);

    vector<double> dvc(ilst.begin(), ilst.end());
    for (auto i: ilst)
        cout << i << " ";
    cout << endl;

    for (auto i: dvc)
        cout << i << " ";
    cout << endl;


    // from vector<int> to vector<double>
    vector<double> dvc2(ivc.begin(), ivc.end());
    for (auto i: ivc)
        cout << i << " ";
    cout << endl;

    for (auto d: dvc2)
        cout << d << " ";


    return 0;
}