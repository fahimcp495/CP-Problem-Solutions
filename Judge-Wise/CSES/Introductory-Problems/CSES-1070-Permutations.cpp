#include<bits/stdc++.h>
using namespace std;
 
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;  cin >> n;
  if(n==2 or n==3){
    cout << "NO SOLUTION\n";
    return 0;
  }
  vector<int> ans;
  for (int i = 1; i < n; i+=2){
    ans.push_back(i+1);
  }
  for (int i = 0; i < n; i+=2){
    ans.push_back(i+1);
  }
  for (int i = 0; i < n; ++i){
    cout << ans[i] << " \n"[i==n-1];
  }
  return 0;
}