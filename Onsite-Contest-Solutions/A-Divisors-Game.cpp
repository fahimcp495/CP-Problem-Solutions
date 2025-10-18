#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;
const int A = 1e6 + 6;
const int G = 32;

int spf[A], g[A];
int n, a[N];
int pref[N][G];

void solve () {
  int n, q; cin >> n >> q;
  vector<int> a(n);
  for (auto &ai: a) {
    cin >> ai;
    ai = g[ai];
  }

  int x = 0;
  pref[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < G; ++j) {
      pref[i + 1][j] = pref[i][j];
    }
    x ^= a[i];
    pref[i + 1][x]++;
  }

  while (q--) {
    int l, r; cin >> l >> r; l--, r--;
    ll second = 0;
    for (int j = 0; j < G; ++j) {
      int cnt = pref[r + 1][j];
      if (l > 0) cnt -= pref[l - 1][j];
      second += 1ll * cnt * (cnt - 1) / 2;
    }

    int len = r - l + 1;
    ll first = 1ll * len * (len + 1) / 2 - second;


    if (first > second) cout << "First\n";
    else if (first < second) cout << "Second\n";
    else cout << "Draw\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  for (int i = 2; i < A; ++i) {
    if (spf[i]) continue;
    for (int j = i; j < A; j += i) {
      if (!spf[j]) spf[j] = i;
    }
  }

  for (int i = 2; i < A; ++i) {
    int j = i;
    while (j > 1) {
      g[i]++;
      j /= spf[j];
    }
  }

  int t; cin >> t;
  while (t--) {
    solve();
  }
}