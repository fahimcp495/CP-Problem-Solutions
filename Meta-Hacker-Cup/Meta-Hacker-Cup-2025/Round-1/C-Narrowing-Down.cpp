#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve () {
  int n; cin >> n;
  vector<int> a(n);
  for (auto &ai: a) {
    cin >> ai;
  }
  ll ans = 0;
  map<int, int> cnt;
  cnt[0] = 1;
  int x = 0;
  for (int r = 0; r < n; ++r) {
    x ^= a[r];
    ll good = 1ll * cnt[x] * (cnt[x] + 1) / 2;
    ll now = 1ll * (r + 1) * (r + 2) / 2 - good;
    ans += now;
    cnt[x]++;
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