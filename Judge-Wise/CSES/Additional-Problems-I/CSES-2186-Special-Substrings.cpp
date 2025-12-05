#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const int A = 26;
 
int main(){
  ios::sync_with_stdio(0), cin.tie(0);
 
  string s;  cin >> s;
  int n = s.size();
 
  int tot = 0;
  for (char c = 'a'; c <= 'z'; ++c) {
    if (count(s.begin(), s.end(), c))  tot++;
  }
 
  map<array<int, 26>, int> cnt;
 
  array<int, 26> f;  f.fill(0);
  cnt[f] = 1;
 
  ll ans = 0;
 
  for (int i = 0; i < n; ++i) {
    int idx = s[i] - 'a';
    f[idx]++;
    if (f[idx] == 1)  tot--;
    int mn = n;
    for (int j = 0; j < A; ++j) {
      if (f[j]) {
        mn = min(mn, f[j]);
      }
    }
 
    array<int, A> ff;
    for (int j = 0; j < A; ++j) {
      if (!f[j])  ff[j] = 0;
      else  ff[j] = f[j] - mn;
    }
 
    if (tot == 0) {
      ans += cnt[ff];
      cnt[ff]++;
    }
    else {
      cnt[f]++;
    }
  }
 
  cout << ans;
 
}
