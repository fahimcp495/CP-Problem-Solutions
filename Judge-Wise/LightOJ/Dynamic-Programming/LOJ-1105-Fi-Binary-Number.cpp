#include<bits/stdc++.h>
using namespace std;

using ll = long long;

string kth(ll k, ll len) {
  vector<array<ll, 2>> cnt(len + 1);
  cnt[0][0] = 1;
  for (int i = 1; i <= len; ++i) {
    cnt[i][0] = cnt[i - 1][0] + cnt[i - 1][1];
    cnt[i][1] = cnt[i - 1][0];
  }

  string ans = "1";

  for (int i = len - 1; i > 0; --i) {
    if (cnt[i][0] >= k) {
      ans += '0';
    }
    else {
      ans += '1';
      k -= cnt[i][0];
    }
  }

  return ans;
}

void solve() {
  ll n;  cin >> n;
  
  ll cnt0 = 0, cnt1 = 1;
  ll len = 1;
  while (n > cnt0 + cnt1) {
    n -= (cnt0 + cnt1);
    ll tmp = cnt0;
    cnt0 += cnt1;
    cnt1 = tmp;
    len++;
  }

  cout << kth(n, len) << '\n';

}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int t;  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case " << i << ": ";
    solve();
  }
}