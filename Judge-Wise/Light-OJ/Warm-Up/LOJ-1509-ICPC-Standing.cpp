#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve () {
    int p, s, r; cin >> p >> s >> r;
    if (s < p) {
        cout << "Yes\n";
    }
    else {
        if (r == 1) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int t; cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve();
    }
}