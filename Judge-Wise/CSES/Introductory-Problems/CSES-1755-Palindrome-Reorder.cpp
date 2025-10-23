#include<bits/stdc++.h>
using namespace std;
 
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  string s; cin >> s;
  vector<int> cnt(26, 0);
  for (int i = 0; s[i]; ++i){
    cnt[s[i]-'A']++;
  }
  char mid = '#';
  string ans;
  for (int i = 0; i < 26; ++i){
    if(cnt[i]&1){
      if(mid=='#')  mid = i+'A', cnt[i]--;
      else {
        cout << "NO SOLUTION\n";
        return 0;
      }
    }
    ans += string(cnt[i]/2, 'A'+i);
  }
  cout << ans;
  if(mid!='#')  cout << mid;
  reverse(ans.begin(), ans.end());
  cout << ans << "\n";
 
  return 0;
}