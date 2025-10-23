#include<bits/stdc++.h>
using namespace std;

const int N=505;
double dp[2][N][N];
int vis[2][N][N];

double pre(int p, int r, int b){
  double &ret = dp[p][r][b];
  if(vis[p][r][b])  return ret;
  vis[p][r][b]=1;
  if(p==1){
    if(b==0)  ret = 0;
    else if(r==0 and b==1) ret=1;
    else  ret=pre(0, r, b-1);
  } else {
    if(r==0 and b==1) ret=1;
    else{
      ret = 0;
      if(r>0) ret += 1.0*r/(r+b)*pre(1, r-1, b);
      if(b>0) ret += 1.0*b/(r+b)*pre(1, r, b-1);
    }
  }
  return ret;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  for (int i = 0; i < N; ++i){
    for (int j = 0; j < N; ++j){
      if(!vis[0][i][j])  pre(0,i,j);
      if(!vis[1][i][j])  pre(1,i,j);
    }
  }

  int T; cin >> T;
  for(int tc=1; tc<=T; tc++){
    cout << "Case " << tc << ": ";
    int r, b; cin >> r >> b;
    cout << fixed << setprecision(10);
    cout << dp[0][r][b] << endl;
  }
  
  return 0;
}