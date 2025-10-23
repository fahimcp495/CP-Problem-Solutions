#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int T; cin >> T;
  for(int tc=1; tc<=T; tc++){
    cout << "Case " << tc << ": ";
    vector<string> s(3);
    int len[3];
    for (int i = 0; i < 3; ++i){
      cin >> s[i];
      len[i] = s[i].size();
    }
    int dp[len[0]+1][len[1]+1][len[2]+1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < len[0]; ++i){
      for (int j = 0; j < len[1]; ++j){
        for (int k = 0; k < len[2]; ++k){
          if (s[0][i] == s[1][j] and s[1][j]==s[2][k]) {
            dp[i+1][j+1][k+1] = dp[i][j][k]+1;
          } else {
            dp[i+1][j+1][k+1] = max({dp[i][j][k], dp[i+1][j+1][k], dp[i][j+1][k+1], dp[i+1][j][k+1], dp[i+1][j][k], dp[i][j+1][k], dp[i][j][k+1]});
          }
        }
      }
    }
    cout << dp[len[0]][len[1]][len[2]] << '\n';
  }
  
  return 0;
}