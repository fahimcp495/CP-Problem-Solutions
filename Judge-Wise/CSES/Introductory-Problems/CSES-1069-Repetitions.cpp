#include<bits/stdc++.h>
using namespace std;
 
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  string s; cin >> s;
  int ans=0, now=0, pre=0;
  for (int i = 0; s[i]; ++i){
    if(s[i]^pre)  ans = max(ans, now), pre = s[i], now = 1;
    else now++;
  }
  cout << max(ans, now) << "\n";
  return 0;
}