#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int T; cin >> T;
  for(int tc=1; tc<=T; tc++){
    cout << "Case " << tc << ": ";
    string s;  cin >> s;
    if (s[4]=='s')  cout << s << '\n';
    else  cout << s.substr(0, 4) + "s" + s.substr(4) << '\n';
  }
  
  return 0;
}