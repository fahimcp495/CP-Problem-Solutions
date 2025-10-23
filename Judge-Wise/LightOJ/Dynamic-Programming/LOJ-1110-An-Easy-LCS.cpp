#include<bits/stdc++.h>
using namespace std;

string lex_lcs(string& s, string& t) {
  int n = s.size();
  int m = t.size();
  int lcs[n+1][m+1];
  string lex[n+1][m+1];
  memset(lcs, 0, sizeof(lcs));
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      if (s[i]==t[j]) {
        lcs[i+1][j+1] = lcs[i][j]+1;
        lex[i+1][j+1] = lex[i][j] + s[i];
      } else if(lcs[i+1][j] > lcs[i][j+1]) {
        lcs[i+1][j+1] = lcs[i+1][j];
        lex[i+1][j+1] = lex[i+1][j];
      } else if(lcs[i+1][j] < lcs[i][j+1]) {
        lcs[i+1][j+1] = lcs[i][j+1];
        lex[i+1][j+1] = lex[i][j+1];
      } else {
        lcs[i+1][j+1] = lcs[i+1][j];
        lex[i+1][j+1] = min(lex[i+1][j], lex[i][j+1]);
      }
    }
  }
  return lex[n][m];
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int T; cin >> T;
  for(int tc=1; tc<=T; tc++){
    cout << "Case " << tc << ": ";
    string s, t;  cin >> s >> t;
    string ans = lex_lcs(s, t);
    if(ans.size()==0) ans = ":(";
    cout << ans << "\n";
  }
  
  return 0;
}