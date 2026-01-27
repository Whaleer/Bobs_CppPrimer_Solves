// 科大讯飞
// 02.K小姐的闹钟计划
#include <iostream>
#include <string>
#include <climits>
using namespace std;

int toMinute(const string &time) {
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3));
    return h * 60 + m;
}

int main() {
    string curTime;
    cin >> curTime;
    int n;
    cin >> n;

    int curMinute = toMinute(curTime);
    int minGap = INT_MAX;
    string res;

    for (int i = 0; i < n; ++i) {
        string alarmTime;
        cin >> alarmTime;
        int alarmMinute = toMinute(alarmTime);
        if (alarmMinute > curMinute) {
            int gap = alarmMinute - curMinute;
            if (gap < minGap) {
                minGap = gap;
                res = alarmTime;
            }
        }
    }
    cout << res << endl;
    return 0;
}


