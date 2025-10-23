#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;  cin >> n;
  vector<int> a, b;
  if((n*(n+1)/2)&1){
    cout << "NO\n";
    return 0;
  }
  ll sum = 1LL*n*(n+1)/4, now = 0;
  for (int i = n; i >= 1; --i){
    if(now+i<=sum)  a.push_back(i), now += i;
    else  b.push_back(i);
  }
  cout << "YES\n";
  cout << a.size() << "\n";
  for(auto& u: a){
    cout << u << " ";
  }
  cout << "\n";
 
  cout << b.size() << "\n";
  for(auto& u: b){
    cout << u << " ";
  }
  cout << "\n";
 
  return 0;
}