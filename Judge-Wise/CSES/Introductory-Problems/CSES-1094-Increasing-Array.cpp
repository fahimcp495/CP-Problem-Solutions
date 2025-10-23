#include<bits/stdc++.h>
using namespace std;
 
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;  cin >> n;
  int a[n];
  for (int i = 0; i < n; ++i){
    cin >> a[i];
  }
  long long ans = 0;
  for (int i = 1; i < n; ++i){
    ans += max(0, a[i-1]-a[i]);
    a[i] = max(a[i], a[i-1]);
  }
  cout << ans << "\n";
  return 0;
}