#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve() {
    int n; cin >> n;
    int m = n * (n - 1) / 2;
    vector<ll> sums(m);
    for (auto &sum: sums) {
        cin >> sum;
    }
    sort(sums.begin(), sums.end());
    ll a1pa2 = sums[0]; // a1 + a2
    ll a1pa3 = sums[1]; // a1 + a3
    ll a2ma3 = a1pa2 - a1pa3;   // a2 - a3
 
    // Iterate over a2 + a3
    for (int j = 2; j < 2 * n - 3; ++j) {
        ll a2pa3 = sums[j];
        if ((a2pa3 + a2ma3) % 2 == 1) continue;
        ll a2 = (a2pa3 + a2ma3) / 2;
        ll a1 = a1pa2 - a2;
        if (a1 <= 0) continue;
 
        vector<ll> a(n);
        a[0] = a1;
 
        multiset<ll> st(sums.begin(), sums.end());
        bool ok = 1;
        for (int i = 1; i < n; ++i) {
            a[i] = *st.begin() - a[0]; st.erase(st.begin());
            if (a[i] < 0) {
                ok = 0;
                break;
            }
            for (int j = 1; j < i; j++) {
                if (st.find(a[j] + a[i]) == st.end()) {
                    ok = 0;
                    break;
                }
                st.erase(st.find(a[j] + a[i]));
            }
            if (!ok) break;
        }
        if (ok) {
            for (auto ai: a) {
                cout << ai << " ";
            }
            cout << "\n";
            return;
        }
 
    }
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    solve();
}
