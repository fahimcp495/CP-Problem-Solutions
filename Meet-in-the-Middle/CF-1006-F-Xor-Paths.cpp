// Problem link: https://codeforces.com/problemset/problem/1006/F

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 20;
const int M = 20;

int n, m;
ll k;
ll a[N][M];

map<ll, ll> dp[N][M], dp2[N][M];

void solve () {
  cin >> n >> m;
  cin >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }

  if (n == 1 and m == 1) {
    cout << (a[0][0] == k) << "\n";
    return ;
  }

  dp[0][0][a[0][0]] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; i + j < n; ++j) {
      if (i > 0) {
        for (auto [x, f]: dp[i - 1][j]) {
          dp[i][j][x ^ a[i][j]] += f;
        }
      }
      if (j > 0) {
        for (auto [x, f]: dp[i][j - 1]) {
          dp[i][j][x ^ a[i][j]] += f;
        }
      }
    }
  }

  dp2[n - 1][m - 1][a[n - 1][m - 1]] = 1;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j + i >= n - 1; --j) {
      if (i + 1 < n) {
        for (auto [x, f]: dp2[i + 1][j]) {
          dp2[i][j][x ^ a[i][j]] += f;
        }
      }
      if (j + 1 < m) {
        for (auto [x, f]: dp2[i][j + 1]) {
          dp2[i][j][x ^ a[i][j]] += f;
        }
      }
    }
  }

  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    int j = n - 1 - i;
    if (j < m) {
      for (auto [x, f]: dp[i][j]) {
        ans += f * dp2[i][j][k ^ x ^ a[i][j]];
      }
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
