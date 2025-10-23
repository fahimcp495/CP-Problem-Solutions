#include<bits/stdc++.h>
using namespace std;

// #include "debug.h"

using ll = long long;

const int N = 1e5+5, INF = 1e9;

int n, k;

int st[4 * N];

void assign(int i, int x, int s = 0, int e = n - 1, int u = 1) {
  if (s > i or e < i) {
    return ;
  }

  if (s == e) {
    st[u] = x;
    return ;
  }

  int m = (s + e) / 2;
  assign(i, x, s, m, 2 * u);
  assign(i, x, m + 1, e, 2 * u + 1);
  st[u] = min(st[2 * u], st[2 * u + 1]);
}

int rmq(int l, int r, int s = 0, int e = n - 1, int u = 1) {
  if (s > r or e < l) {
    return INF;
  }
  if (l <= s and e <= r) {
    return st[u];
  }
  int m = (s + e) / 2;
  return min(rmq(l, r, s, m, 2 * u), rmq(l, r, m + 1, e, 2 * u + 1));
}

void solve() {
  cin >> n >> k;
  vector<int> a(n);
  for (auto &ai: a) {
    cin >> ai;
  }

  a.push_back(-INF);
  n++;
  sort(a.begin(), a.end());

  for (int i = 0; i < 4 * n; ++i) {
    st[i] = INF;
  }

  assign(0, 0);

  for (int i = 3; i < n; ++i) {
    auto j = lower_bound(a.begin(), a.begin() + i, a[i] - 2 * k) - a.begin();
    if (j <= i - 2) {
      assign(i, min(rmq(j - 1, i - 3) + 1, INF));
    }
  }

  int ans = rmq(n - 1, n - 1);
  if (ans == INF) {
    ans = -1;
  }

  cout << ans << '\n';

}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int t;  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case " << i << ": ";
    solve();
  }
}