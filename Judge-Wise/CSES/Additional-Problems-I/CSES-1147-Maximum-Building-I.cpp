#include<bits/stdc++.h>
using namespace std;
 
vector<int> nsel(vector<int>& a){  //nearest smaller in left
  int n = a.size();
  vector<int> idx(n);
  stack<int> s;
  s.push(-1);
  for (int i = 0; i < n; ++i){
    while (s.top() != -1 and a[s.top()] >= a[i])  s.pop();
    idx[i]=s.top();
    s.push(i);
  }
  return idx;
}
 
int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int n, m;  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; ++i){
    cin >> s[i];
  }
  vector<int> a(m);
  int ans = 0;
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      if (s[i][j]=='.')  a[j]++;
      else a[j] = 0;
    }
    vector<int> l = nsel(a);
 
    vector<int> b = a;
    reverse(b.begin(), b.end());
    vector<int> r = nsel(b);
    reverse(r.begin(), r.end());
    for (int j = 0; j < m; ++j){
      r[j] = m-1-r[j];
    }
    for (int j = 0; j < m; ++j){
      ans = max(ans, (r[j]-l[j]-1)*a[j]);
    }
  }
 
  cout << ans << "\n";
  
  return 0;
}
