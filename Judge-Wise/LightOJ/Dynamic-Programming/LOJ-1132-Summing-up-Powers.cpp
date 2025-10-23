#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using row = vector<unsigned>;
using matrix = vector<row>;

matrix unit_mat(int n) {
  matrix I(n, row(n));
  for (int i = 0; i < n; ++i) {
    I[i][i] = 1;
  }
  return I;
}

matrix mat_mul(matrix a, matrix b) {
  int m = a.size(), n = a[0].size();
  int p = b.size(), q = b[0].size();
  matrix res(m, row(q));
  for (int i = 0; i < m; ++i){
    for (int j = 0; j < q; ++j){
      for (int k = 0; k < n; ++k){
        res[i][j] += a[i][k]*b[k][j];
      }
    }
  }
  return res;
}

matrix mat_exp(matrix a, ll p) {
  int m = a.size(), n = a[0].size();
  matrix res = unit_mat(m);
  while (p) {
    if (p&1)  res = mat_mul(a, res);
    a = mat_mul(a, a);
    p >>= 1;
  }
  return res;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  unsigned nCr[55][55];
  memset(nCr, 0, sizeof(nCr));
  for (int i = 0; i < 55; ++i){
    nCr[i][0] = 1;
    for (int j = 1; j <= i; ++j){
      nCr[i][j] = nCr[i-1][j-1] + nCr[i-1][j];
    }
  }
  
  int T; cin >> T;
  for(int tc=1; tc<=T; tc++){
    cout << "Case " << tc << ": ";
    ll n, k;  cin >> n >> k;
    matrix b(k+2, row(k+2));
    b[0][0] = 1;
    for (int i = 1; i < k+2; ++i){
      b[0][i] = nCr[k][i-1];
    }
    for (int i = 1; i < k+2; ++i){
      for (int j = i; j < k+2; ++j){
        b[i][j] = nCr[k-i+1][j-i];
      }
    }
    matrix res = mat_exp(b, n-1);
    unsigned ans = 0;
    for (int j = 0; j < k+2; ++j){
      ans += res[0][j];
    }
    cout << ans << "\n";
  }
  
  return 0;
}