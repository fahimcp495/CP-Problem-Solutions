#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N=102;

int dp[N][N];

string s;

int rec(int l, int r) {
  int& ret = dp[l][r];
  if (ret != -1)  return ret;
  if (l>=r)  return ret = 0;
  if (s[l]==s[r])  return ret = rec(l+1, r-1);
  else return ret = 1+min(rec(l+1, r), rec(l, r-1));
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int T; cin >> T;
  for(int tc=1; tc<=T; tc++){
    cout << "Case " << tc << ": ";
    cin >> s;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, s.size()-1) << '\n';
  }
  
  return 0;
}