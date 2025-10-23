#include<bits/stdc++.h>
using namespace std;

const int N=15;

int n, p[N][N];
int dp[1<<N];

int f(int mask) {
  if(mask==(1<<n)-1) return 0;
  int &ret = dp[mask];
  if(ret != -1) return ret;
  ret = 1e9;
  for (int i = 0; i < n; ++i){
    if ((mask&(1<<i)) == 0) {
      int cur = p[i][i];
      for (int j = 0; j < n; ++j){
        if(mask & (1<<j)) {
          cur += p[i][j];
        }
      }
      ret = min(ret, cur+f(mask|(1<<i)));
    }
  }
  return ret;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int T; cin >> T;
  for(int tc=1; tc<=T; tc++){
    cout << "Case " << tc << ": ";
    cin >> n;
    for (int i = 0; i < n; ++i){
      for (int j = 0; j < n; ++j){
        cin >> p[i][j];
      }
    }
    memset(dp, -1, sizeof(dp));
    cout << f(0) << "\n";
  }
  
  return 0;
}

//dp[mask] means minimum cost for completing the jobs which are 0 in mask now after comleting jobs which are 1 in mask