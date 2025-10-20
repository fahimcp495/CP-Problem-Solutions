/*
for len: 1 0 to m-1
  for c: alpha
    dp[i][ls(s, len+c)] += dp[i-1][len]
*/

/*
O(*50^3log(1e9))
gonna get TLE
*/

#include<bits/stdc++.h>
using namespace std;
using ll = unsigned;
using row = vector<ll>;
using matrix = vector<row>;

matrix unit_mat(int n) {
  matrix u(n, row(n));
  for (int i = 0; i < n; ++i){
    u[i][i] = 1;
  }
  return u;
}

matrix mat_mul(matrix& a, matrix& b) {
  int m = a.size(), n = a[0].size();
  int p = b.size(), q = b[0].size();
  matrix prod(m, row(q));
  for (int i = 0; i < m; ++i){
    for (int j = 0; j < q; ++j){
      for (int k = 0; k < n; ++k){
        prod[i][j] = (prod[i][j] + a[i][k]*b[k][j]);
      }
    }
  }
  return prod;
}

matrix mat_exp(matrix& a, ll p) {
  int n = a.size();
  matrix ret = unit_mat(n);
  while (p){
    if (p&1)  ret = mat_mul(ret, a);
    a = mat_mul(a, a);
    p >>= 1;
  }
  return ret;
}

//KMP::O(|s|)
vector<int> cal_pi(string s){
  int n = s.size();
  vector<int> pi(n);
  for (int k = 0, i = 1; i < n; ++i){
    if(s[i]==s[k])  pi[i] = ++k;
    else if(k==0) pi[i]=0;
    else  k = pi[k-1], --i;
  }
  return pi;
}


int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int T; cin >> T;
  for(int tc=1; tc<=T; tc++){
    cout << "Case " << tc << ": ";
    int n;  cin >> n;
    string alpha;  cin >> alpha;
    string s;  cin >> s;
    int m = s.size();
    matrix b(m+1, row(m+1));
    for (int len = 0; len < m; ++len) {
      for (char& ch: alpha) {
        vector<int> pi = cal_pi(s+'#'+s.substr(0, len)+ch);
        int l = pi.back();
        b[m-l][m-len]++;
      }
    }
    matrix res = mat_exp(b, n);
    ll ans = 0;
    for (int i = 1; i <= m; ++i){
      ans += res[i][m];
    }
    cout << ans << '\n';
  }

  return 0;
}

