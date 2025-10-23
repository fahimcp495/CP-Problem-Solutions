#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=102;
const int INF=1e9;

int n;
ll a[N];
ll pref[N];
ll dp[N][N];

int f(int l, int r){
  if(l>r) return 0;
  ll &ret = dp[l][r];
  if(ret!=-INF)  return ret;
  for (int i = l; i <=r; ++i){
    ll now = pref[i+1] - pref[l] - f(i+1, r);
    ret = max(ret, now);
  }
  for (int i = r; i >= l; --i){
    ll now = pref[r+1] - pref[i] - f(l, i-1);
    ret = max(ret, now);
  }
  return ret;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int T; cin >> T;
  int tc=0;
  while(T--){
    cout << "Case " << ++tc << ": "; 
    cin >> n;
    for (int i = 0; i < n; ++i){
      cin >> a[i];
      pref[i+1] = pref[i] + a[i];
    }
    for (int i = 0; i < N; ++i){
      for (int j = 0; j < N; ++j){
        dp[i][j]=-INF;
      }
    }
    cout << f(0, n-1) << "\n";
  }
  
  return 0;
}