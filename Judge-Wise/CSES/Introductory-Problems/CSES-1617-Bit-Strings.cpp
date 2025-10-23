#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const ll mod = 1e9+7;
 
ll bigmod(ll a, ll p, ll m){
  a %= m;
  ll ret = 1;
  while(p){
    if(p&1) ret = ret*a%mod;
    a = a*a%mod;
    p >>= 1;
  }
  return ret;
}
 
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;  cin >> n;
  cout << bigmod(2, n, mod) << "\n";
 
  return 0;
}