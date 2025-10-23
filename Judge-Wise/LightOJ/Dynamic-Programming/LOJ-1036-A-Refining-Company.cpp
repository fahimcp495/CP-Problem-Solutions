#include<bits/stdc++.h>
using namespace std;

// #include "debug.h"

using ll = long long;

void solve() {
  int m, n;  cin >> m >> n;
  ll a[m][n];
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }

  ll b[m][n];
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> b[i][j];
    }
  }

  ll suf[m][n + 1];
  memset(suf, 0, sizeof(suf));

  for (int i = 0; i < m; ++i) {
    for (int j = n - 1; j >= 0; --j) {
      suf[i][j] = b[i][j] + suf[i][j + 1];
    }
  }

  ll dp[m + 1][n + 1];
  memset(dp, 0, sizeof(dp));

  for (int i = 0; i < m; ++i) {
    dp[i + 1][0] = dp[i][0] + suf[i][0];
    ll pref = 0;
    ll mx = dp[i][0];
    for (int j = 0; j < n; ++j) {
      mx = max(mx, dp[i][j + 1]);
      pref += a[i][j];
      dp[i + 1][j + 1] = mx + pref + suf[i][j + 1];
    }
  }

  ll ans = 0;

  for (int j = 0; j <= n; ++j) {
    ans = max(ans, dp[m][j]);
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

