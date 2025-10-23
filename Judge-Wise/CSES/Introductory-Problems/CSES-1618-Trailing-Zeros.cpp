#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const ll mod = 1e9+7;
 
int p_v(int n){
  int ret = 0;
  int p = 5;
  while(n/p){
    ret += n/p;
    p *= 5;
  }
  return ret;
}
 
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;  cin >> n;
  cout << p_v(n) << "\n";
 
  return 0;
}