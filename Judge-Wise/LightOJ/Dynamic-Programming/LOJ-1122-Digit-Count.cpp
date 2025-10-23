#include<bits/stdc++.h>
using namespace std;

int m, n;
int d[10];
int ans = 0;

void rec(int idx, int ld) { //index and last digit
  if(idx==n) {
    ans++;
    return ;
  }
  for (int i = 0; i < m; ++i){
    if(abs(ld-d[i]) <= 2) {
      rec(idx+1, d[i]);
    }
  }
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int T; cin >> T;
  for(int tc=1; tc<=T; tc++){
    cout << "Case " << tc << ": ";
    cin >> m >> n;
    ans = 0;
    for (int i = 0; i < m; ++i){
      cin >> d[i];
    }
    for (int i = 0; i < m; ++i){
      rec(1, d[i]);
    }
    cout << ans << "\n";
  }
  
  return 0;
}