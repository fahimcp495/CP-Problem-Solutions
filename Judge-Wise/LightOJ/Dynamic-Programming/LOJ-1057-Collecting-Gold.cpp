#include<bits/stdc++.h>
using namespace std;

const int INF = 1000;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int T; cin >> T;
  for(int tc=1; tc<=T; tc++){
    cout << "Case " << tc << ": ";
    int n, m;  cin >> n >> m;
    vector<int> x, y;
    int sp;
    for (int i = 0; i < n; ++i){
      string si;  cin >> si;
      for (int j = 0; j < m; ++j){
        if (si[j]=='x') sp=x.size();
        if (si[j]!='.') {
          x.push_back(i);
          y.push_back(j);
        }
      }
    }
    int g = x.size();
    int dp[16][1<<16];
    for (int i = 0; i < g; ++i){
      for (int mask = 0; mask < (1<<g); ++mask) {
        dp[i][mask] = INF;
      }
    }
    dp[sp][1<<sp] = 0;
    auto dis = [&] (int i, int j) {
      return max(abs(x[i]-x[j]), abs(y[i]-y[j]));
    };
    for (int mask = 0; mask < (1<<g); ++mask) {
      for (int i = 0; i < g; ++i) {
        if (dp[i][mask] == INF)  continue;
        for (int j = 0; j < g; ++j){
          dp[j][mask|(1<<j)] = min(dp[j][mask|(1<<j)], dp[i][mask]+dis(i, j));
        }
      }
    }
    cout << dp[sp][(1<<g)-1] << '\n';
  }
  
  return 0;
}