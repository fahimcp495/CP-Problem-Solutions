// Problem link: https://cses.fi/problemset/task/1628/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 1e9 + 9;

vector<int> subset_sum (vector<int> a) {
  int sz = a.size();
  vector<int> ret;
  int MASK = 1 << sz;
  for (int mask = 0; mask < MASK; ++mask) {
    int sum = 0;
    for (int i = 0; i < sz; ++i) {
      if (mask >> i & 1) {
        sum += a[i];
        sum = min(sum, inf);
      }
    }
    ret.push_back(sum);
  }
  return ret;
}

void solve () {
  int n, x; cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> L(a.begin(), a.begin() + n / 2);
  vector<int> R(a.begin() + n / 2, a.end());
  vector<int> sumL = subset_sum(L);
  vector<int> sumR = subset_sum(R);

  ll ans = 0;
  sort(sumR.begin(), sumR.end());
  for (auto l: sumL) {
    ll now = upper_bound(sumR.begin(), sumR.end(), x - l) - lower_bound(sumR.begin(), sumR.end(), x - l);
    ans += now;
  }
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
