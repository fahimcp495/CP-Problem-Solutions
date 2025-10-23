#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int T; cin >> T;
  for(int tc=1; tc<=T; tc++){
    cout << "Case " << tc << ": ";
    string s;  cin >> s;
    int n = s.size();


    ll dp[n+1][n+1][2][2];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i){
      dp[i][i][1][1] = 1;
      if (i<n) {
        dp[i][i+1][0][1] = 1;
        dp[i][i+1][1][0] = 1;
        dp[i][i+1][1][1] = s[i-1]==s[i];
      }
    }
    for (int len = 3; len <= n; ++len) {
      for (int i = 0; i+len <= n; ++i){
        dp[i+1][i+len][0][0] = dp[i+2][i+len-1][0][0] + dp[i+2][i+len-1][0][1] + dp[i+2][i+len-1][1][0] +dp[i+2][i+len-1][1][1];
        dp[i+1][i+len][0][1] = dp[i+2][i+len][0][1] + dp[i+2][i+len][1][1];
        dp[i+1][i+len][1][0] = dp[i+1][i+len-1][1][0] + dp[i+1][i+len-1][1][1];
        dp[i+1][i+len][1][1] = (s[i]==s[i+len-1]) * (dp[i+2][i+len-1][0][0] + dp[i+2][i+len-1][0][1] + dp[i+2][i+len-1][1][0] + dp[i+2][i+len-1][1][1] + 1);
      }
    }

    ll ans = 0;
    for (int i = 0; i < 2; ++i){
      for (int j = 0; j < 2; ++j){
        ans += dp[1][n][i][j];
      }
    }
    cout << ans << '\n';
  }
  
  return 0;
}


/*
dp[i][j][0][0]: ways for substring i to j deleting s[i] and s[j]
dp[i][j][0][1]: ways for substring i to j deleting s[i] and not deleting s[j]
dp[i][j][1][0]: ways for substring i to j not deleting s[i] and deleting s[j]
dp[i][j][1][1]: ways for substring i to j not deleting s[i] and not deleting s[j]
*/