#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int T, tc = 0; cin >> T;
  while(T--){
    int r, c; cin >> r >> c;
    ll ans;
    if(r>=c){
      if(r&1){
        ans = 1LL*(r-1)*(r-1)+c;
      } else {
        ans = 1LL*(r-1)*(r-1)+2*r-c;
      }
    } else {
      if(c&1^1){
        ans = 1LL*(c-1)*(c-1)+r;
      } else {
        ans = 1LL*(c-1)*(c-1)+2*c-r;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}