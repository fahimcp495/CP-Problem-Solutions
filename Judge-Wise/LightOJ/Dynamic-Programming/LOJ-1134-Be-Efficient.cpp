#include<bits/stdc++.h>
using namespace std;

// #include "debug.h"

using ll = long long;

void solve() {
  int n, m;  cin >> n >> m;
  vector<int> a(n);
  for (auto &ai: a) {
    cin >> ai;
  }

  map<int, int> cnt;
  cnt[0] = 1;
  int pref_sum = 0;
  ll ans = 0;
  for (auto ai: a) {
    pref_sum += ai;
    pref_sum %= m;
    ans += cnt[pref_sum];
    cnt[pref_sum]++;
  }
  cout << ans << "\n";
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int tt;  cin >> tt;
  for (int t = 1; t <= tt; ++t) {
    cout << "Case " << t << ": ";
    solve();
  }
}