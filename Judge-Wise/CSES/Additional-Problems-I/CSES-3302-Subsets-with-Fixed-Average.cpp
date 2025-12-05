#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const int mod = 1e9 + 7;
 
void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}
 
void solve() {
    int n, a; cin >> n >> a;
    vector<int> x(n);
    int neg = 0, pos = 0;
    for (auto &xi: x) {
        cin >> xi;
        xi -= a;
        if (xi < 0) neg += -xi;
        else pos += xi;
    }
    int tot = neg + pos + 1;
    vector<int> dp(tot); dp[neg] = 1;
    for (auto xi: x) {
        if (xi < 0) continue;
        auto new_dp = dp;
        for (int j = pos - xi; j >= -neg; --j) {
            add(new_dp[neg + j + xi], dp[neg + j]);
        }
        dp = new_dp;
    }
    for (auto xi: x) {
        if (xi >= 0) continue;
        auto new_dp = dp;
        for (int j = -neg - xi; j <= pos; ++j) {
            add(new_dp[neg + j + xi], dp[neg + j]);
        }
        dp = new_dp;
    }
    cout << (dp[neg] - 1 + mod) % mod << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
 
    solve();
}
