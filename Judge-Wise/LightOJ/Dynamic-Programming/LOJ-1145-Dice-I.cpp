#include<bits/stdc++.h>
using namespace std;

// #include "debug.h"

using ll = long long;

const ll mod = 1e8+7;

void solve() {
  int n, k, s;  cin >> n >> k >> s;
  vector<ll> dp(s + 1);
  dp[0] = 1;

  for (int i = 0; i < n; ++i) {
    vector<ll> pref(s + 2);
    pref[1] = dp[0];
    for (int j = 2; j <= s; ++j) {
      pref[j] = (pref[j - 1] + dp[j - 1]) % mod;
    }

    vector<ll> new_dp(s + 1);
    for (int j = 1; j <= s; ++j) {
      new_dp[j] = (pref[j] - pref[max(0, j - k)] + mod) % mod;
    }

    dp = new_dp;
  }

  cout << dp[s] << "\n";
}


int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int tt;  cin >> tt;
  for (int t = 1; t <= tt; ++t) {
    cout << "Case " << t << ": ";
    solve();
  }
}