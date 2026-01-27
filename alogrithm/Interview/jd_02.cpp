//
// Created by Bingxi L on 2024/8/15.
//
#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

constexpr int MAXN = 2e6 + 7;

int n, x;
int a[MAXN];
map<int, int> mp;

signed main() {

    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int y = x - a[i];
        ans += mp[y];
    }
    cout << ans << endl;

    return 0;
}