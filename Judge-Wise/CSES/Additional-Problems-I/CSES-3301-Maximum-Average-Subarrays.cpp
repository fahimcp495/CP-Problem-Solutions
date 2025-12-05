#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
struct comp {
    bool operator() (const array<ll, 3> &a, const array<ll, 3> &b) const {
        auto [l1, r1, s1] = a;
        auto [l2, r2, s2] = b;
        return make_pair(s1 * (r2 - l2 + 1), -r1) < make_pair(s2 * (r1 - l1 + 1), -r2);
    }
};
 
void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (auto &ai: a) {
        cin >> ai;
    }
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }
    set<array<ll, 3>, comp> st;
    vector<int> L(n), R(n);
    for (int i = 0; i < n; ++i) {
        st.insert({i, i, a[i]});
        R[i] = i, L[i] = i;
    }
    vector<int> ans(n);
 
    auto greater = [&] (int l1, int r1, int l2, int r2) {
        return (pref[r1 + 1] - pref[l1]) * (r2 - l2 + 1) > (pref[r2 + 1] - pref[l2]) * (r1 - l1 + 1);
    };
 
    auto add = [&] (int l, int r) {
        st.insert({l, r, pref[r + 1] - pref[l]});
        R[l] = r, L[r] = l;
    };
 
    while (!st.empty()) {
        auto [l2, r2, s2] = *st.rbegin(); st.erase(prev(st.end()));
        if (l2 == 0) {
            ans[r2] = r2 - l2 + 1;
            if (r2 < n - 1) {
                int l3 = r2 + 1, r3 = R[l3];
                if (st.find({l3, r3, pref[r3 + 1] - pref[l3]}) != st.end()) {
                    st.erase({l3, r3, pref[r3 + 1] - pref[l3]});
                    l3 = l2;
                    add(l3, r3);
                }
            }
            continue;
        }
 
        int r1 = l2 - 1, l1 = L[r1];
        if (!greater(l2, r2, l1, r1)) {
            l2 = l1;
            add(l2, r2);
        }
        else {
            ans[r2] = r2 - l2 + 1;
            if (r2 < n - 1) {
                int l3 = r2 + 1, r3 = R[l3];
                if (st.find({l3, r3, pref[r3 + 1] - pref[l3]}) != st.end()) {
                    st.erase({l3, r3, pref[r3 + 1] - pref[l3]});
                    l3 = l2;
                    add(l3, r3);
                }
            }
        }
    }
 
    for (auto x: ans) {
        cout << x << ' ';
    }
    cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
 
    solve();
}