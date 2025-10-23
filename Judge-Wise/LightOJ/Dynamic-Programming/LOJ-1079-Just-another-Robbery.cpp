#include<bits/stdc++.h>
using namespace std;

const int N=10004;

double dp[N];

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int T; cin >> T;
  for(int tc=1; tc<=T; tc++){
    cout << "Case " << tc << ": ";
    double P; cin >> P;
    int n;  cin >> n;
    double p[n+1];
    int m[n+1];
    for (int i = 1; i <= n; ++i){
      cin >> m[i] >> p[i];
    }
    for (int i = 0; i < N; ++i){
      dp[i]=2;
    }
    dp[0]=0;
    int ans = 0;
    for (int i = 1; i <= n; ++i){
      for (int j = N-1; j > 0; --j){
        if(j-m[i]<0)  break;
        double prb = dp[j-m[i]];
        prb = prb+(1-prb)*p[i];
        if(prb<P){
          dp[j] = min(dp[j], prb);
          ans = max(ans, j);
        }
      }
    }
    cout << ans << endl;
  }
  
  return 0;
}