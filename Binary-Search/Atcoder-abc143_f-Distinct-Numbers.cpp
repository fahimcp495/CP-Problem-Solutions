// Problem link: https://atcoder.jp/contests/abc143/tasks/abc143_f

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define dbg(a)  cerr << #a << " " << a << "\n"

void solve() {
  int n;  cin >> n;
  vector<int> a(n), cnt(n);
  for (auto &ai: a) {
    cin >> ai;  ai--;
    cnt[ai]++;
  }

  vector<int> pref(n + 1), suf(n + 2);
  for (int i = 0; i < n; ++i) {
    pref[cnt[i]] += cnt[i];
    suf[cnt[i]]++;
  }
  for (int i = 1; i <= n; ++i) {
    pref[i] += pref[i - 1];
  }
  for (int i = n - 1; i > 0; --i) {
    suf[i] += suf[i + 1];
  }

  for (int k = 1; k <= n; ++k) {
    int lo = 0, hi = n / k;
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      ll tot = pref[mid] + (suf[mid + 1]) * mid;
      if (tot >= mid * k)  lo = mid + 1;
      else  hi = mid - 1;
    }
    cout << hi << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int tc = 1;
  for (int t = 1; t <= tc; ++t) {
    solve();
  }
}
