#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int T; cin >> T;
  for(int tc=1; tc<=T; tc++){
    cout << "Case " << tc << ": ";
    string s, t;  cin >> s >> t;
    int m = s.size(), n = t.size();
    int lis[m+1][n+1];
    ll ways[m+1][n+1];
    memset(lis, 0, sizeof(lis));
    memset(ways, 0, sizeof(ways));
    for (int i = 0; i <= m; ++i){
      ways[i][0] = 1;
    }
    for (int j = 0; j <= n; ++j){
      ways[0][j] = 1;
    }
    for (int i = 0; i < m; ++i){
      for (int j = 0; j < n; ++j){
        if (s[i]==t[j]) {
          lis[i+1][j+1] = lis[i][j] + 1;
          ways[i+1][j+1] = ways[i][j];
        } else {
          lis[i+1][j+1] = max(lis[i+1][j], lis[i][j+1]);
          if (lis[i+1][j+1] == lis[i+1][j]) {
            ways[i+1][j+1] += ways[i+1][j];
          }
          if (lis[i+1][j+1] == lis[i][j+1]) {
            ways[i+1][j+1] += ways[i][j+1];
          }
        }
      }
    }

    cout << m+n-lis[m][n] << ' ' << ways[m][n] << '\n';
  }
  
  return 0;
}