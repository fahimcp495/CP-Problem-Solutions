#include<bits/stdc++.h>
using namespace std;

int n, x[16], y[16], dp[1<<16];
vector<int> same[16][16];

int co_linear(int i, int j, int k) {
  return x[i]*y[j]+x[j]*y[k]+x[k]*y[i] == y[i]*x[j]+y[j]*x[k]+y[k]*x[i];
}

int rec(int mask) {
  int& ret = dp[mask];
  if (ret != -1)  return ret;
  int i, cnt = 0;
  for (int idx = 0; idx < n; ++idx){
    if (!(mask&(1<<idx))) {
      cnt++;
      i = idx;
    }
  }
  if (cnt==0)  return ret = 0;
  if (cnt<=2)  return ret = 1;

  ret = n;
  vector<int> done(n);
  for (int j = 0; j < n; ++j){
    if (j==i or (mask&(1<<j)) or done[j]) continue;
    int new_mask = mask | (1<<i) | (1<<j);
    done[j] = 1;
    for (int& k: same[i][j]) {
      new_mask |= 1<<k;
      done[k] = 1;
    }
    ret = min(ret, 1+rec(new_mask));
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
      cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; ++i){
      for (int j = 0; j < n; ++j){
      same[i][j].clear();
      if (j==i)  continue;
        for (int k = 0; k < n; ++k){
          if (k==j or k==i)  continue;
          if (co_linear(i, j, k)) {
            same[i][j].push_back(k);
          }
        }
      }
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(0) << '\n';
  }
  
  return 0;
}