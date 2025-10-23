#include<bits/stdc++.h>
using namespace std;

#define dbg(a) cerr<<__LINE__<<": "<<#a<<" = "<<a<<'\n'

typedef long long ll;

const int mod = 1e9+7;
const int N = 1e3+3;

ll fact[N], invf[N];
ll dp[N][N];

ll bigmod(ll a, ll b, ll mod){
  a %= mod;
  ll ret = 1;
  while(b){
    if(b&1) ret = ret*a%mod;
    a = a*a%mod;
    b >>= 1;
  }
  return ret;
}

void pc_ncr() {
  fact[0] = 1;
  for (int i = 1; i < N; ++i){
    fact[i] = fact[i-1]*i%mod;
  }
  invf[N-1] = bigmod(fact[N-1], mod-2, mod);
  for (int i = N-2; i >= 0; --i){
    invf[i] = invf[i+1]*(i+1)%mod;
  }
}

ll nCr(int n, int r) {
  if(n<r) return 0;
  return fact[n]*invf[r]%mod*invf[n-r]%mod;
}

ll f(int a, int b) {
  if(a<0) return 0;
  if(a==0)  return fact[b];
  if(dp[a][b] != -1)  return dp[a][b];
  ll ret = (a-1)*((f(a-2, b)+f(a-1, b))%mod)%mod + b*f(a-1, b)%mod;
  ret %= mod;
  return dp[a][b] = ret;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  pc_ncr();
  memset(dp, -1, sizeof(dp));

  int T; cin >> T;
  for(int tc=1; tc<=T; tc++){
    cout << "Case " << tc << ": ";
    int n, m, k;  cin >> n >> m >> k;
    ll ans = nCr(m, k)*f(m-k, n-m)%mod;
    cout << ans << "\n";
  }
  
  return 0;
}