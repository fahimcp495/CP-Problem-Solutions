#include<bits/stdc++.h>
using namespace std;

//KMP
vector<int> cal_pi(string s){
  int n = s.size();
  vector<int> pi(n);
  for (int k = 0, i = 1; i < n; ++i){
    if(s[i]==s[k])  pi[i] = ++k;
    else if(k==0) pi[i]=0;
    else  k = pi[k-1], --i;
  }
  return pi;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int T; cin >> T;
  for(int tc=1; tc<=T; tc++){
    cout << "Case " << tc << ": ";
    string s; cin >> s;
    int n = s.size();
    string rss = s;      //reverse s + '#' + s
    reverse(s.begin(), s.end());
    rss = s + "#" + rss;
    vector<int> pi = cal_pi(rss);
    cout << 2*n-pi.back() << "\n";
  }
  
  return 0;
}