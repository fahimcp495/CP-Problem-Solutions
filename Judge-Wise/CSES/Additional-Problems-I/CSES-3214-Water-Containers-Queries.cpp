#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve() {
    int a, b, x; cin >> a >> b >> x;
    if (a >= x and x % gcd(a, b) == 0) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
