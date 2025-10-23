#include<bits/stdc++.h>
using namespace std;
using row = vector<int>;
using matrix = vector<row>;

matrix reshape(matrix& a, int n, int m) {
  matrix ret(n+m-1);
  for (int k = 0; k < n+m-1; ++k) {
    for (int i = k; i >= 0; --i) {
      int j = k-i;
      ret[k].push_back(a[i][j]);
    }
  }
  return ret;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int T; cin >> T;
  for(int tc=1; tc<=T; tc++){
    cout << "Case " << tc << ": ";
    int n, m;  cin >> n >> m;
    matrix a(n+m-1, row(n+m-1));
    for (int i = 0; i < n; ++i){
      for (int j = 0; j < m; ++j){
        cin >> a[i][j];
      }
    }
    matrix aa = reshape(a, n, m);
    matrix dp = {{0, aa[1][0]+aa[1][1]}, {0, 0}};
    for (int i = 2; i < n+m-2; ++i){
      matrix cur_dp(i+1, row(i+1));
      for (int j = 0; j < i; ++j) {
        for (int jj = j+1; jj < i+1; ++jj) {
          if (j==0) {
            if (jj==i) {
              cur_dp[j][jj] = dp[j][jj-1];
            } else if (jj==1) {
              cur_dp[j][jj] = dp[j][jj];
            } else {
              cur_dp[j][jj] = max({dp[j][jj], dp[j][jj-1]});
            }
          } else if (jj==i) {
            if (j==i-1) {
              cur_dp[j][jj] = dp[j-1][jj-1];
            } else {
              cur_dp[j][jj] = max({dp[j-1][jj-1], dp[j][jj-1]});
            }
          } else {
            if (j+1==jj) {
              cur_dp[j][jj] = max({dp[j-1][jj-1], dp[j-1][jj], dp[j][jj]});
            } else {
              cur_dp[j][jj] = max({dp[j-1][jj-1], dp[j-1][jj], dp[j][jj-1], dp[j][jj]});
            }
          }
          cur_dp[j][jj] += aa[i][j] + aa[i][jj];
        } 
      }
      dp = cur_dp;
    }
    cout << a[0][0]+dp[m-2][m-1]+a[n-1][m-1] << '\n';
  }
  
  return 0;
}