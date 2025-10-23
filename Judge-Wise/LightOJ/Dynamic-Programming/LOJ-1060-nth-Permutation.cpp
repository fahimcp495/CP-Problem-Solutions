#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  ll fact[21];  fact[0] = 1;
  for (int i = 1; i < 21; ++i) {
    fact[i] = fact[i-1]*i;
  }

  int T; cin >> T;
  for(int tc=1; tc<=T; tc++){
    cout << "Case " << tc << ": ";
    string s;  cin >> s;
    int n;  cin >> n;
    int m = s.size();
    vector<int> cnt(26);
    for (int i = 0; i < m; ++i){
      cnt[s[i]-'a']++;
    }
    string ans(m, '0');
    int pos = 1;
    for (int i = 0; i < m; ++i) {
      int ok = 0;
      for (int j = 0; j < 26; ++j){
        if (!cnt[j])  continue;
        cnt[j]--;
        ll ways = fact[m-i-1];
        for (int j = 0; j < 26; ++j){
          ways /= fact[cnt[j]];
        }
        if (ways >= n) {
          ans[i] = 'a'+j;
          ok = 1;
          break;
        }
        n -= ways;
        cnt[j]++;
      }
      if (!ok) {
        pos = 0;
        break;
      }
    }
    if (!pos)  cout << "Impossible\n";
    else cout << ans << '\n';
  }
  
  return 0;
}