#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using row = vector<ll>;
using matrix = vector<row>;

int val(char ch) {
  if (isdigit(ch))  return ch-'0';
  else return ch-'A'+10;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int T; cin >> T;
  for(int tc=1; tc<=T; tc++){
    cout << "Case " << tc << ": ";  
    int b, k;  cin >> b >> k;
    string s;  cin >> s;
    int n = s.size();

    matrix dp(k, row(1<<n));  dp[0][0] = 1;
    for (int mask = 0; mask < (1<<n); ++mask){
      for (int idx = 0; idx < n; ++idx) {
        if (!(mask&(1<<idx))) {
          for(int rem = 0; rem < k; ++rem){
            dp[(rem*b+val(s[idx]))%k][mask|(1<<idx)] += dp[rem][mask];
          }
        }
      }
    }
    cout << dp[0][(1<<n)-1] << '\n';
  }
  
  return 0;
}