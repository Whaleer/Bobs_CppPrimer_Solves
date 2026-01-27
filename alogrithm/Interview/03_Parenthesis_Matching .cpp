// 科大讯飞
// 03.K小姐的括号匹配问题
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Pair(char c1, char c2, string left, string right) {
    if (left.find(c1) != string::npos && right.find(c2) != string::npos) {
        if (left.find(c1) == right.find(c2)) {
            return 0;
        } else {
            return 1;
        }
    } else {
        return 2;
    }
}

int minReplace(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, n));
    string left = "([{<";
    string right = ")]}>";

    for (int i = 0; i < n - 1; i++) {
        dp[i][i + 1] = Pair(s[i], s[i + 1], left, right);
    }

    for (int len = 4; len <= n; len += 2) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            dp[i][j] = dp[i + 1][j - 1] + Pair(s[i], s[j], left, right);
            for (int k = i + 1; k < j; k += 2)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
        }
    }
    return dp[0][n - 1];
}

int main() {
    string s;
    cin >> s;
    cout << minReplace(s) << "\n";
    return 0;
}

