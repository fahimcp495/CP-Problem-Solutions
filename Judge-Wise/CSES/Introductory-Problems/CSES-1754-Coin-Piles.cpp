#include<bits/stdc++.h>
using namespace std;
 
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int T, tc = 0; cin >> T;
  while(T--){
    int a, b; cin >> a >> b;
    if(a<b) swap(a, b);
    if(a<=2*b and (a+b)%3==0) cout << "YES\n";
    else  cout << "NO\n";
  }
 
  return 0;
}