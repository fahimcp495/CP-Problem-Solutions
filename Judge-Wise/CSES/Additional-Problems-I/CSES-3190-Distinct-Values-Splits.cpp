#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const int mod = 1e9 + 7;
 
void sub(ll &a, ll b) {
    a -= b;
    if (a < 0) a += mod;
}
 
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &ai: a) {
        cin >> ai;
    }
    vector<ll> dp(n + 1); dp[0] = 1;
    vector<ll> pref(n + 1); pref[0] = 1;
    int L = 0;
    map<int, int> idx;
    for (int i = 0; i < n; ++i) {
        dp[i + 1] = pref[i];
        if (idx.count(a[i])) {
            L = max(L, idx[a[i]]);
        }
        if (L) {
            sub(dp[i + 1], pref[L - 1]);
        }
        pref[i + 1] = (pref[i] + dp[i + 1]) % mod;
        idx[a[i]] = i + 1;
    }
    cout << dp[n] << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
 
    int t = 1;
    while (t--) {
        solve();
    }
 
}
