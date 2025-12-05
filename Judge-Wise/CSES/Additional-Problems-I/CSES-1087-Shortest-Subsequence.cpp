#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
 
int main(){
  ios::sync_with_stdio(0), cin.tie(0);
 
  string s;  cin >> s;
 
  vector<int> got(26);
  int cnt = 0;
  string ans;
  for (char c: s) {
    got[c - 'A']++;
    if (got[c - 'A'] == 1) {
      cnt++;
 
      if (cnt == 4) {
        ans += c;
        got.assign(26, 0);
        cnt = 0;
      }
    }
  }
 
  if (!got[0]) {
    ans += 'A';
  }
  else if (!got[2]) {
    ans += 'C';
  }
  else if (!got[6]) {
    ans += 'G';
  }
  else {
    ans += 'T';
  }
 
  cout << ans << "\n";
}