// Problem link: https://cses.fi/problemset/task/1083

#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int n;  cin >> n;
  vector<int> a(n), f(n+1, 0);
  for (int i = 0; i < n-1; ++i){
    cin >> a[i];
    f[a[i]]++;
  }
  for (int i = 1; i <= n; ++i){
    if(f[i]==0)  cout << i << "\n";
  }
  return 0;
}
