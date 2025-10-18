#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve () {
  int n, a, b; cin >> n >> a >> b;
  vector<int> ans(2 * n, 1);
  ans.back() = b;
  for (int i = 0; i < 2 * n; ++i) {
    cout << ans[i] << " \n"[i == 2 * n - 1];
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int t; cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}