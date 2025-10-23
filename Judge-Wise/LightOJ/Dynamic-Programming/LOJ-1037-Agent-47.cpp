#include<bits/stdc++.h>
using namespace std;

const int N=15;

int n, a[N];
vector<string> s(N);
int dp[1<<N];

int rec(int mask) {
  int& ret = dp[mask];
  if (ret != -1)  return ret;
  if (mask+1 == 1<<n)  return ret=0;
  ret = 1e8;
  for (int i = 0; i < n; ++i) {
    if (!(mask&(1<<i))) {
      int mx = 1;
      for (int j = 0; j < n; ++j){
        if (mask&(1<<j)) {
          mx = max(mx, s[j][i]-'0');
        }
      }
      ret = min(ret, (a[i]+mx-1)/mx+rec(mask|(1<<i)));
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
      cin >> a[i];
    }
    for (int i = 0; i < n; ++i){
      cin >> s[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(0) << '\n';
  }
  return 0;
}