#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &ai: a) {
        cin >> ai;
    }
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&] (int i, int j) {
        return make_pair(a[i], i) < make_pair(a[j], j);
    });
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, idx[i] - i);
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