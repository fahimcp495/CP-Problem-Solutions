#include<bits/stdc++.h>
using namespace std;
 
int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int n;  cin >> n;
  vector<string> g(1<<n);
  g[0] = "0";
  g[1] = "1";
  for (int i = 1; i < n; ++i){
    int len = 1<<i;
    for (int j = 0; j < len; ++j){
      g[len+j] = g[len-1-j];
      g[len-1-j] += '0';
      g[len+j] += '1';
    }
  }
  for (int i = 0; i < (1<<n); ++i){
    reverse(g[i].begin(), g[i].end());
    cout << g[i] << "\n";
  }
  
  return 0;
}