#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
 
  ll n, k;  cin >> n >> k;
  vector<ll> a(n);
  for (auto &ai: a) {
    cin >> ai;
  }
  a.insert(a.end(), a.begin(), a.end());
  vector<ll> pref(2 * n + 1);
  for (int i = 0; i < 2 * n; ++i) {
    pref[i + 1] = pref[i] + a[i];
  }
 
  int LG = 20;
  ll par[2 * n + 1][LG];
  for (int j = 0; j < LG; ++j) {
    par[2 * n][j] = 2 * n;
  }
 
  for (int i = 2 * n - 1; i >= 0; --i) {
    par[i][0] = upper_bound(pref.begin() + i, pref.end(), pref[i] + k) - pref.begin() - 1;
    for (int j = 1; j < LG; ++j) {
      par[i][j] = par[par[i][j - 1]][j - 1];
    }
  }
 
  int ans = n;
 
  for (int l = n - 1; l >= 0; --l) {
    int r = l, now = 0;
    for (int j = LG - 1; j >= 0; --j) {
      if (par[r][j] < l + n) {
        r = par[r][j];
        now += 1 << j;
      }
    }
    ans = min(ans, now + 1);
  }
 
  cout << ans << "\n";
}