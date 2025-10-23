#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int T; cin >> T;
  for(int tc=1; tc<=T; tc++){
    cout << "Case " << tc << ": ";
    int n, x;  cin >> n >> x;
    vector<ll> dp(6*n+1); dp[0] = 1;
    for (int i = 0; i < n; ++i){
      vector<ll> cur_dp(6*n+1);
      for (int j = 1; j <= 6*n; ++j){
        for (int k = 1; k <= 6; ++k){
          if (j>=k) {
            cur_dp[j] += dp[j-k];
          }
        }
      }
      dp = cur_dp;
    }
    ll pos_ways = 0;
    for (int i = x; i <= 6*n; ++i){
      pos_ways += dp[i];
    }
    ll tot_ways = 1;
    while (n--){
      tot_ways *= 6;
    }

    ll g = __gcd(pos_ways, tot_ways);
    pos_ways /= g;
    tot_ways /= g;
    cout << pos_ways;
    if (tot_ways>1)  cout << "/" << tot_ways;
    cout << '\n';
  }
  
  return 0;
}