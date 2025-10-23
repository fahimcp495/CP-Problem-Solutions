#include<bits/stdc++.h>
using namespace std;

#define dbg(a)  cerr << #a << " = " << a << "\n";

int a, b, k;
string s;
int cnt[11][100][100];

int count(int idx=0, int rem=0, int drem=0, bool small=0){
  if(s[idx]=='\0'){
    if(rem==0 and drem==0)  return 1;
    else  return 0;
  }
  int &ret = cnt[idx][rem][drem];
  if(ret!=-1 and small){
   return ret;
  }
  ret = 0;
  int lmt = small ? 9: s[idx]-'0';
  for (int i = 0; i <= lmt; ++i){
    ret += count(idx+1, (rem*10+i)%k, (drem+i)%k, small|(i<lmt));
  }
  return ret;
}

int f(int n){
  s = to_string(n);
  memset(cnt, -1, sizeof(cnt));
  return count();
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int T, tc = 0; cin >> T;
  while(T--){
    cout << "Case " << ++tc << ": ";
    cin >> a >> b >> k;
    if(k>82){
      cout << "0\n";
      continue;
    }
    int ans = f(b)-f(a-1);
    cout << ans << "\n";
  }
  return 0;
}