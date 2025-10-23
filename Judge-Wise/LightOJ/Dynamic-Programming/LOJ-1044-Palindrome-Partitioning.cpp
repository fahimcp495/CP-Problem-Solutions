#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int T; cin >> T;
  for(int tc=1; tc<=T; tc++){
    cout << "Case " << tc << ": ";
    string s;  cin >> s;
    int n = s.size();
    
    int is_pal[n][n];
    memset(is_pal, 0, sizeof(is_pal));

    for (int len = 1; len <= n; ++len) {
      for (int st = 0; st+len <= n; ++st) {
        int ok = (s[st]==s[st+len-1]);
        if (len>2) {
          ok = ok and is_pal[st+1][st+len-2];
        }
        is_pal[st][st+len-1] = ok; 
      }
    }

    vector<int> dp(n+1, n);  dp[0] = 0;
    int ans = n;
    for (int j = 0; j < n; ++j){
      for (int i = 0; i <= j; ++i){
        if (is_pal[i][j]) {
          dp[j+1] = min(dp[j+1], dp[i]+1);
        }
      }
    }
    cout << dp[n] << '\n';

  }
  
  return 0;
}