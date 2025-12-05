#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &ai: a) {
        cin >> ai;
    }
    vector<int> b(n);
    for (auto &bi: b) {
        cin >> bi;
    }
 
    auto ok = [&] (double avg) {
        double asum = a[0] - avg, amx = a[0] - avg;
        int l = 0;
        for (int i = 1; i < n; ++i) {
            asum += a[i] - avg;
            if (asum > amx) {
                amx = asum;
                l = i;
            }
        }
 
        double bsum = b[0] - avg, bmx = b[0] - avg;
        int r = 0;
        for (int i = 1; i < n; ++i) {
            bsum += b[i] - avg;
            if (bsum > bmx) {
                bmx = bsum;
                r = i;
            }
        }
 
        if (amx + bmx >= 0) {
            return make_pair(l, r);
        }
        else {
            return make_pair(-1, -1);
        }
    };
 
    double lo = 0, hi = 1e9;
    int itr = 100;
    while (itr--) {
        double mid = (lo + hi) / 2;
        if (ok(mid) != make_pair(-1, -1)) lo = mid;
        else hi = mid;
    }
    auto [L, R] = ok(lo);
    cout << L + 1 << " " << R + 1 << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    solve();
}
