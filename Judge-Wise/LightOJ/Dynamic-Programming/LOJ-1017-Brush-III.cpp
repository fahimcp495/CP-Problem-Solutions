#include<bits/stdc++.h>
using namespace std;

const int N=102;

int n, w, k;
int x[N], y[N];

int dp[N][N];

int f(int idx, int rem){
  int &ret=dp[idx][rem];
  if(ret!=-1) return ret;
  if(rem==0)  ret=0;
  else {
    int nxt = upper_bound(y, y+n, y[idx]+w)-y;
    ret = 0;
    for (int i = nxt; i < n; ++i){
      ret = max(ret, f(i, rem-1));
    }
    ret += nxt-idx;
  }
  return ret;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int T; cin >> T;
  for(int tc=1; tc<=T; tc++){
    cout << "Case " << tc << ": ";
    cin >> n >> w >> k;
    for (int i = 0; i < n; ++i){
      cin >> x[i] >> y[i];
    }
    sort(y, y+n);
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < n; ++i){
      ans = max(ans, f(i, k));
    }
    cout << ans << endl;
  }
  
  return 0;
}