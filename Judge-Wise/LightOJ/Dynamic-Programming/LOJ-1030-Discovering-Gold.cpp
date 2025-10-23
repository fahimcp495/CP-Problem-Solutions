#include<bits/stdc++.h>
using namespace std;

const int N=110;

int n, a[N];
double dp[N];

double f(int pos){
  if(pos>=n) return 0;
  double &ret = dp[pos];
  if(ret!=-1) return ret;
  ret = 0;
  int i;
  for (i = 1; i <= 6; ++i){
    if(i+pos>n) break;
    ret += a[pos+i]+f(pos+i);
  }
  ret /= i-1;
  return ret;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int T; cin >> T;
  for(int tc=1; tc<=T; tc++){
    cout << "Case " << tc << ": ";
    cin >> n;
    for (int i = 1; i <= n; ++i){
      cin >> a[i];
    }
    for (int i = 0; i < N; ++i){
      dp[i]=-1;
    }
    cout << fixed << setprecision(15);
    cout << f(1)+a[1] << endl;
  }
  
  return 0;
}


/*
dp[n] = number of expected gold starting at n excluding gold at a[n]
f(n) = 1/6*f((n+1)+a[n+1]) + 1/6*(f(n+2)+a[n+2]) + 1/6*f((n+3)+a[n+3]) + 1/6*(f(n+4)+a[n+4]) + 2/6*f(n) ; here assuming n+4==size, n=5, n=6 out of bound
f(n)-2/6*f(n) = 1/6*(f(n+1)+dp[n+1] + f(n+2)+dp[n+2] + f(n+3)+dp[n+3] + f(n+4) + dp[n+4])
4/6*f(n) = 1/6*(f(n+1)+dp[n+1] + f(n+2)+dp[n+2] + f(n+3)+dp[n+3] + f(n+4) + dp[n+4])
f(n) = 1/4*(f(n+1)+dp[n+1] + f(n+2)+dp[n+2] + f(n+3)+dp[n+3] + f(n+4) + dp[n+4])
*/