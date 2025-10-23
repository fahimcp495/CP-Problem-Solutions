#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int T; cin >> T;
  for(int tc=1; tc<=T; tc++){
    cout << "Case " << tc << ": ";
    string s;  cin >> s;
    int d;  cin >> d;
    sort(s.begin(), s.end());
    int n = s.size();
    int dp[1<<n][d];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int mask = 0; mask < (1<<n); ++mask) {
      for (int rem = 0; rem < d; ++rem) {
        if (dp[mask][rem]==0)  continue;
        vector<int> used(10);
        for (int i = 0; i < n; ++i) {
          if (used[s[i]-'0'])  continue;
          if (!(mask&(1<<i))) {
            dp[mask|(1<<i)][(rem*10+s[i]-'0')%d] += dp[mask][rem];
            used[s[i]-'0'] = 1;
          }
        }
      }
    }
    cout << dp[(1<<n)-1][0] << '\n';
  }
  
  return 0;
}