#include<bits/stdc++.h>
using namespace std;

bool is_vow(char ch) {
  return ch=='A' or ch=='E' or ch=='I' or ch=='O' or ch=='U';
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int T; cin >> T;
  for(int tc=1; tc<=T; tc++){
    cout << "Case " << tc << ": ";
    string s;  cin >> s;
    int n = s.size();

    vector<int> cons_vow(n+1), cons_con(n+1);
    for (int i = 0; i < n; ++i){
      if (s[i]=='?')  cons_vow[i+1] = 0, cons_con[i+1] = 0;
      else if (is_vow(s[i]))  cons_vow[i+1] = cons_vow[i] + 1, cons_con[i+1] = 0;
      else cons_con[i+1] = cons_con[i] + 1, cons_vow[i+1] = 0;
    }

    //check if bad
    int bad = 0;
    int v = 0, c = 0;
    for (int i = n-1; i >= 0; --i){
      if (s[i]=='?') {
        if (cons_vow[i]+1+v >= 3 and cons_con[i]+1+c >= 5 )  bad = 1;
        else if (cons_vow[i]+1+v >= 3)  c++, v=0;
        else if (cons_con[i]+1+c >= 5)  v++, c=0;
        else {
          v = 0;
          c = 0;
        }
      } else if (is_vow(s[i])) {
        v++;
        c = 0;
        if (cons_vow[i]+v >= 3)  bad = 1;
      } else {
        c++;
        v = 0;
        if (cons_con[i]+c >= 5)  bad = 1;
      }
    }

    //check if good
    int good = 1;
    v = 0, c = 0;
    for (int i = n-1; i >= 0; --i){
      if (s[i]=='?') {
        if (cons_vow[i]+1+v >= 3 or cons_con[i]+1+c >= 5)  good = 0;
        v++, c++;
      } else if (is_vow(s[i])) {
        v++;
        c = 0;
        if (cons_vow[i]+v >= 3)  good = 0;
      } else {
        c++;
        v = 0;
        if (cons_con[i]+c >= 5)  good = 0;
      }
    }

    assert(!(bad and good));

    if (bad)  cout << "BAD\n";
    else if (good)  cout << "GOOD\n";
    else cout << "MIXED\n";
  }
  
  return 0;
}