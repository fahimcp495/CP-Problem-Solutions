#include <bits/stdc++.h>
using namespace std;

void solve () {
  int n; cin >> n;
  vector<int> a(n);
  for (auto &ai: a) {
    cin >> ai;
  }
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    ans = max(ans, abs(a[i] - a[i - 1]));
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int t; cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}