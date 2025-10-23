#include<bits/stdc++.h>
using namespace std;
 
const int A = 26;
 
int main(){
  ios::sync_with_stdio(0), cin.tie(0);
 
  string s;  cin >> s;
 
  int n = s.size();
  vector<int> cnt(A);
  for (char c: s) {
    cnt[c - 'A']++;
  }
 
  for (int c = 0; c < A; ++c) {
    if (cnt[c] > (n - cnt[c]) + 1) {
      puts("-1");
      return 0;
    }
  }
 
  string ans;
 
  for (int i = 0; i < n; ++i) {
    int mx = *max_element(cnt.begin(), cnt.end());
    for (int c = 0; c < A; ++c) {
      if (cnt[c] > 0 and (i == 0 or ans.back() != c + 'A')) {
        if (cnt[c] == mx) {
          ans += c + 'A';
          cnt[c]--;
          break;
        }
        else if (mx <= (n - i - 1 - mx) + 1) {
          ans += c + 'A';
          cnt[c]--;
          break;
        }
      }
    }
  }
 
  cout << ans;
}