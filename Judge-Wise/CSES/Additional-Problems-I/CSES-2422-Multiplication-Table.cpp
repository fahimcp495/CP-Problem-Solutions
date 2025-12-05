#include<bits/stdc++.h>
using namespace std;

using ll = long long;
 
void solve() {
  ll n;  cin >> n;
  ll lo = 1, hi = n * n;
  ll k = n * n / 2 + 1;
 
  while (lo <= hi) {
    ll mid = (lo + hi) / 2;
    ll cnt = 0;
    for (int i = 1; i <= n; ++i) {
      cnt += min(n, mid / i);
    }
 
    if (cnt >= k) {
      hi = mid - 1;
    }
    else {
      lo = mid + 1;
    }
  }
 
  cout << lo << '\n';
 
 
}
 
int main(){
  ios::sync_with_stdio(0), cin.tie(0);
 
  int tt = 1;
  for (int t = 1; t <= tt; ++t) {
    solve();
  }
}
