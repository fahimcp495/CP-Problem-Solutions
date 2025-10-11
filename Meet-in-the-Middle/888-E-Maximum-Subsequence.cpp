// Problem link: https://codeforces.com/contest/888/problem/E


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;

vector<int> subset_sum (vector<int> a) {
  int sz = a.size();
  vector<int> ret;
  int MASK = 1 << sz;
  for (int mask = 0; mask < MASK; ++mask) {
    int sum = 0;
    for (int i = 0; i < sz; ++i) {
      if (mask >> i & 1) {
        sum += a[i];
        if (sum >= m) sum -= m;
      }
    }
    ret.push_back(sum);
  }
  return ret;
}

void solve () {
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] %= m;
  }

  vector<int> L(a.begin(), a.begin() + n / 2);
  vector<int> R(a.begin() + n / 2, a.end());
  vector<int> sumL = subset_sum(L);
  vector<int> sumR = subset_sum(R);

  int ans = 0;
  sort(sumR.begin(), sumR.end());
  for (auto l: sumL) {
    auto it = lower_bound(sumR.begin(), sumR.end(), m - l);
    if (it != sumR.begin()) {
      it--;
      int now = l + (*it);
      ans = max(ans, now);
    }
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
