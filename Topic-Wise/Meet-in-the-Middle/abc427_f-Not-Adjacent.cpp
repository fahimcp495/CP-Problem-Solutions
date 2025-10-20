// Problem link: https://atcoder.jp/contests/abc427/tasks/abc427_f

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 60;

int n, m;
int a[N];

vector<int> fn (int l, int r) {
  vector<int> prev_dp = {0}, dp = {0};
  for (int i = l; i <= r; ++i) {
    vector<int> new_dp = dp;
    for (auto x: prev_dp) {
      x += a[i];
      if (x >= m) x -= m;
      new_dp.push_back(x);
    }
    prev_dp = dp;
    dp = new_dp;
  }
  return dp;
}

ll yo (int l1, int r1, int l2, int r2) {
  auto vals = fn(l1, r1);
  auto vals2 = fn(l2, r2);
  sort(vals2.begin(), vals2.end());
  ll ans = 0;
  for (auto x: vals) {
    int now = upper_bound(vals2.begin(), vals2.end(), (m - x) % m) - lower_bound(vals2.begin(), vals2.end(), (m - x) % m);
    ans += now;
  }
  return ans;
}

void solve () {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << 1 + (a[0] == 0) << "\n";
    return ;
  }
  ll ans = yo(0, n / 2 - 2, n / 2, n - 1) + yo(0, n / 2 - 1, n / 2 + 1, n - 1) - yo(0, n / 2 - 2, n / 2 + 1, n - 1);
  cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
