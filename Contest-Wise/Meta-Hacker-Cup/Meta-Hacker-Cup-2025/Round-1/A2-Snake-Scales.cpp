#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve () {
  int n; cin >> n;
  vector<ll> a(n);
  for (auto &ai: a) {
    cin >> ai;
  }
  ll lo = 1, hi = 1e9;
  while (lo <= hi) {
    ll mid = (lo + hi) >> 1;
    int ok = 1;
    int i = 0;
    while (i < n) {
      ll mn = a[i];
      while (i + 1 < n and abs(a[i] - a[i + 1]) <= mid) {
        i++;
        mn = min(mn, a[i]);
      }
      if (mn > mid) ok = 0;
      i++;
    }
    if (ok) hi = mid - 1;
    else lo = mid + 1;
  }
  cout << lo << "\n";
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int t; cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}