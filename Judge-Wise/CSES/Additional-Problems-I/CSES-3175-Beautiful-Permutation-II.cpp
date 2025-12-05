#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve() {
    int n; cin >> n;
    vector<int> p(n);
    int i = 0, od = 1, ev = 2;
 
    auto add = [&] (int &x, int itr) {
        while (i < n and x <= n and itr--) {
            p[i++] = x, x += 2;
        }
    };
 
    auto is_beautiful = [&] {
        for (int i = 0; i + 1 < n; ++i) {
            if (abs(p[i] - p[i + 1]) == 1) return false;
        }
        return true;
    };
 
    add(od, 3);
    
    while (i < n) {
        add(ev, 5);
        add(od, 5);
    }
 
    while (!is_beautiful() and next_permutation(p.begin(), p.end())) {
        // Nothing
    }
 
    if (!is_beautiful()) {
        cout << "NO SOLUTION\n";
    }
    else {
        for (auto pi: p) {
            cout << pi << ' ';
        }
        cout << '\n';
    }
 
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
 
    int t = 1;
    while (t--) {
        solve();
    }
 
}
