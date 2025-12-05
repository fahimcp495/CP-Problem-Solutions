#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using row = vector<int>;
using matrix = vector<row>;
 
const int mod = 1e9 + 7;
 
int n, k;
 
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
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < q; ++j) {
            for (int k = 0; k < n; ++k) {
                res[i][j] = (res[i][j] + 1ll * a[i][k] * b[k][j]) % mod;
            }
        }
    }
    return res;
}
 
matrix mat_expo(matrix a, int p) {
    int m = a.size(), n = a[0].size();
    matrix res = unit_mat(m);
    while (p) {
        if (p & 1) res = mat_mul(a, res);
        a = mat_mul(a, a);
        p >>= 1;
    }
    return res;
}
 
ll fn(int e) {
    matrix B = {{1, e}, {1, 0}};
    B = mat_expo(B, n - 1);
    matrix C = {{e + 1}, {1}};
    return mat_mul(B, C)[0][0];
}
 
void solve() {
    cin >> n >> k;
 
    ll ans = 1;
    for (int i = 2; i * i <= k; ++i) {
        if (k % i == 0) {
            int e = 0;
            while (k % i == 0) {
                k /= i;
                e++;
            }
            ans = ans * fn(e) % mod;
        }
    }
    if (k > 1) {
        ans = ans * fn(1) % mod;
    }
    cout << ans << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
