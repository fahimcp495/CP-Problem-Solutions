// Problem link: https://codeforces.com/contest/912/problem/E

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 1e18;

int n;
vector<int> primes;
ll k;
vector<ll> good[2];

void rec (int i, ll x) {
  if (x > inf) return ;
  if (i >= primes.size()) {
    good[i & 1].push_back(x);
    return ;
  }
  if (x <= inf / primes[i]) rec(i, x * primes[i]);
  rec(i + 2, x);
}

void solve () {
  cin >> n;
  primes.resize(n);
  for (auto &p: primes) {
    cin >> p;
  }
  cin >> k;
  
  rec(0, 1);
  rec(1, 1);
  sort(good[0].begin(), good[0].end());
  sort(good[1].begin(), good[1].end());

  ll lo = 1, hi = inf;
  while (lo <= hi) {
    ll mid = (lo + hi) >> 1;
    ll cnt = 0;
    for (auto x: good[0]) {
      ll now = upper_bound(good[1].begin(), good[1].end(), mid / x) - good[1].begin();
      if (now == 0) break;
      cnt += now;
    }
    if (cnt >= k) hi = mid - 1;
    else lo = mid + 1;
  }
  cout << lo << "\n";
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
