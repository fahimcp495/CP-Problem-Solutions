#include <bits/stdc++.h>
using namespace std;
 
void solve () {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << (i ^ j) << " \n"[j == n - 1];
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
 
    int t = 1;
    while (t--) {
        solve();
    }
}