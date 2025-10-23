#include<bits/stdc++.h>
using namespace std;
 
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  string s; cin >> s;
  sort(s.begin(), s.end());
  set<string> st;
  st.insert(s);
  while(next_permutation(s.begin(), s.end())){
    st.insert(s);
  }
  cout << st.size() << "\n";
  for(auto& ans: st){
    cout << ans << "\n";
  }
  return 0;
}