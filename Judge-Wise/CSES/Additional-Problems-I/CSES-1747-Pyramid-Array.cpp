#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define dbg(a)  cerr << #a << ": " << a << "\n"
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
 
  int n;  cin >> n;
  vector<int> a(n);
  for (auto &ai: a) {
    cin >> ai;
  }
  vector<int> idx(n);
  iota(idx.begin(), idx.end(), 0);
  sort(idx.begin(), idx.end(), [&] (int i, int j) {
    return a[i] > a[j];
  });
 
  vector<int> ft(n + 1);
  auto add = [&] (int i, int x) {
    i++;
    while (i <= n) {
      ft[i] += x;
      i += -i & i;
    }
  };
  auto csum = [&] (int i) {
    i++;
    int ret = 0;
    while (i > 0) {
      ret += ft[i];
      i -= -i & i;
    }
    return ret;
  };
  auto rsum = [&] (int l, int r) {
    return csum(r) - csum(l - 1);
  };
 
  vector<int> cnt(n );
  for (auto i: idx) {
    cnt[i] = rsum(0, i);
    add(i, 1);
  }
 
  ll ans = 0;
  fill(ft.begin(), ft.end(), 0);
  for (auto i: idx) {
    cnt[i] = min(cnt[i], rsum(i, n - 1));
    add(i, 1);
    ans += cnt[i];
  }
 
  cout << ans << "\n";
}
