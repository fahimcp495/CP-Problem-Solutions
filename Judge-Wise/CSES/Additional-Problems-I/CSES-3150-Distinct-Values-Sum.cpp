#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &ai: a) {
        cin >> ai;
    }
    ll ans = 0;
    map<int, int> idx;
    for (int i = 0; i < n; ++i) {
        ans += 1ll * (i + 1 - idx[a[i]]) * (n - i);
        idx[a[i]] = i + 1;
    }
    cout << ans << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
 
    int t = 1;
    while (t--) {
        solve();
    }
 
}