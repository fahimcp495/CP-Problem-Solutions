#include<bits/stdc++.h>
using namespace std;

int n, k;

void rec(string s, int idx, vector<int> vis){
  if(k<=0) return ;
  if(idx==n) {
    cout << s << "\n";
    k--;
    return ;
  }
  for (int i = 0; i < n; ++i){
    if(vis[i])  continue;
    s += 'A'+i;
    vis[i]=1;
    rec(s, idx+1, vis);
    s.pop_back();
    vis[i]=0;
  }
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int T; cin >> T;
  for(int tc=1; tc<=T; tc++){
    cout << "Case " << tc << ":\n";
    cin >> n >> k;
    string s;
    vector<int> vis(n);
    rec(s, 0, vis);
  }
  
  return 0;
}