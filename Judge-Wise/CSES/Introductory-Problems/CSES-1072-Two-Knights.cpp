#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;  cin >> n;
  int a[]={0, 6, 28};
  for (int i = 0; i < min(n, 3); ++i){
    cout << a[i] << "\n";
  }
  for (int i = 4; i <= n; ++i){
    ll ans = 1LL*i*i*(i*i-1);
    ll minus = 4*2 + 8*3 + 4*(i-4)*4 + 4*4 + 4*(i-4)*6 + (i-4)*(i-4)*8;
    ans -= minus;
    cout << ans/2 << "\n";
  }
  return 0;
}