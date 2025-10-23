#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int T; cin >> T;
  for(int tc=1; tc<=T; tc++){
    cout << "Case " << tc << ": ";
    ll n;  cin >> n;  n++;
    ll ans = 0;
    for (int idx = 30; idx >= 1; --idx) {
      ll d = 1ll<<(idx+1);
      ans += n/d*(d/4) + max(0ll, n%d-d/4*3);
    }
    cout << ans << "\n";
  }
  
  return 0;
}