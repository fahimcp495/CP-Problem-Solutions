#include <bits/stdc++.h>
using namespace std;
 
void solve () {
    int n, m; cin >> n >> m;
    vector<string> s(n);
    for (auto &si: s) {
        cin >> si;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if ((i + j) & 1) {
                if (s[i][j] != 'A') s[i][j] = 'A';
                else s[i][j] = 'B';
            }
            else {
                if (s[i][j] != 'C') s[i][j] = 'C';
                else s[i][j] = 'D';
            }
        }
    }
    for (auto si: s) {
        cout << si << "\n";
    }
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
 
    int t = 1;
    while (t--) {
        solve();
    }
}