// Problem link: https://atcoder.jp/contests/abc300/tasks/abc300_g

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;
int P;
vector<int> primes;
vector<ll> smooth[2];

void rec (int i, ll x) {
  if (x > n) return ;
  if (i >= primes.size()) {
    smooth[i & 1].push_back(x);
    return ;
  }
  rec(i, x * primes[i]);
  rec(i + 2, x);
}

void solve () {
  cin >> n >> P;
  for (int i = 2; i <= P; ++i) {
    int isp = 1;
    for (int j = 2; j < i; ++j) {
      if (i % j == 0) {
        isp = 0;
      }
    }
    if (isp) primes.push_back(i);
  }
  rec(0, 1);
  rec(1, 1);
  ll ans = 0;
  sort(smooth[1].begin(), smooth[1].end());
  for (auto x: smooth[0]) {
    ll now = upper_bound(smooth[1].begin(), smooth[1].end(), n / x) - smooth[1].begin();
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
