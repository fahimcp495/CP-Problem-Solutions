#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=202, M=11, D=22;

ll dp[N][M][D];

int n, q;
ll a[N], b[N];
int d, m;

ll go(int i, int j, int k) {
  if(j==0) return i>=0 and k==0;
  else if(i==0) return (j==0 and k==0);
  else if (dp[i][j][k] != -1) return dp[i][j][k];
  else return dp[i][j][k] = go(i-1, j-1, (((k-b[i-1])%d)+d)%d ) + go(i-1, j, k);
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int T; cin >> T;
  for(int tc=1; tc<=T; tc++){
    cout << "Case " << tc << ":\n";
    cin >> n >> q;
    for (int i = 0; i < n; ++i){
      cin >> a[i];
    }

    while (q--){
      cin >> d >> m;
      if(m>n) {
        cout << "0\n";
        continue;
      }
      for (int i = 0; i < n; ++i){
        b[i] = a[i]%d;
        if(b[i]<0)  b[i] += d;
      }
      memset(dp, -1, sizeof(dp));
      cout << go(n, m, 0) << "\n";
    }
  }
  
  return 0;
}

/*
dp[i][j][k] means number of groups of j people from first i people with sum modulo k
*/