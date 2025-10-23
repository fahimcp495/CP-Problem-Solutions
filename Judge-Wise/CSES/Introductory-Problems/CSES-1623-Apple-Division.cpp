#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;  cin >> n;
  int a[n];
  for (int i = 0; i < n; ++i){
    cin >> a[i];
  }
  ll ans = 1e18, sum = accumulate(a, a+n, 0LL);
  for (int i = 0; i < (1<<n)-1; ++i){
    ll now = 0;
    for (int j = 0; j < n; ++j){
      if(i&(1<<j)){
        now += a[j];
      }
    }
    ans = min(ans, abs((sum-now)-now));
  }
  cout << ans << "\n";
  return 0;
}