#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
ll pw10[12];
ll dp[12][12][2][2];

ll go(int idx, int d, int is_small, int nz) {
  if(idx==s.size()-1) return (nz and d==0);
  if(is_small and nz) {
    if(d!=0)  return pw10[s.size()-idx-2]*(s.size()-idx-1);
    else  return pw10[s.size()-idx-2]*(s.size()-idx-1) + pw10[s.size()-idx-1];
  }
  if(dp[idx][d][is_small][nz] != -1)  return dp[idx][d][is_small][nz];
  ll ret = (nz and d==0)*(stol(s.substr(idx+1))+1);
  int lim = is_small? 9: s[idx+1]-'0';
  for (int i = 0; i <= lim; ++i){
    ret += go(idx+1, i, (is_small | i<lim), (nz | (i!=0)));
  }
  return dp[idx][d][is_small][nz] = ret;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  pw10[0] = 1;
  for (int i = 1; i < 12; ++i){
    pw10[i] = pw10[i-1]*10;
  }
  
  int T; cin >> T;
  for(int tc=1; tc<=T; tc++){
    cout << "Case " << tc << ": ";
    ll n, m; cin >> n >> m;
    s = to_string(m);
    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    int lim = s[0]-'0';
    for (int d = 0; d <= lim; ++d){
      ans += go(0, d, d<lim, d!=0);
    }
    if(n==0)  ans++;
    else {
      s = to_string(n-1);
      memset(dp, -1, sizeof(dp));
      int lim = s[0]-'0';
      for (int d = 0; d <= lim; ++d){
        ans -= go(0, d, d<lim, d!=0);
      }
    }
    cout << ans << "\n";
  }
  
  return 0;
}