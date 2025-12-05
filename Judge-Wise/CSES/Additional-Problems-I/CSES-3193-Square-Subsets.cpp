#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const int mod = 1e9 + 7;
const int A = 5001;
const int D = 669;
 
using Basis = array<bitset<D>, D>;
 
vector<int> isp(A, 1), primes;
 
bool add(Basis &b, bitset<D> &x) {
    for (int i = D - 1; i >= 0; --i) {
        if (!x.test(i)) continue;
        if (!b[i].count()) return b[i] = x, true;
        x ^= b[i];
    }
    return false;
}
 
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int rnk = 0;
    Basis B;
    for (auto &ai: a) {
        cin >> ai;
        bitset<D> mask;
        for (int i = 0; i < D; ++i) {
            while (ai % primes[i] == 0) {
                ai /= primes[i];
                mask.flip(i);
            }
        }
        assert(ai == 1);
        rnk += add(B, mask);
    }
    ll ans = 1;
    while (rnk < n) {
        ans = 2 * ans % mod;
        rnk++;
    }
    cout << ans << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
 
    isp[0] = isp[1] = 0;
    for (int i = 2; i < A; ++i) {
        if (isp[i]) {
            primes.push_back(i);
            for (int j = i + i; j < A; j += i) {
                isp[j] = 0;
            }
        }
    }
 
    solve();
}
