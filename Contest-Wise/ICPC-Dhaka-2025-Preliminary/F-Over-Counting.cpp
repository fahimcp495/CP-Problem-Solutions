#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 2e5 + 5;

ll fact[N], ifact[N];

void add(ll &a, ll b) {
	a += b;
	if (a >= mod) a -= mod;
}

ll poww(ll a, ll b) {
	ll ret = 1;
	while (b) {
		if (b & 1) ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}

ll ncr(int n, int r) {
	return fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}

ll get(int z, int o) {
	ll ret = ncr(z + o, 2) * ncr(z + o - 2, z - 1) % mod;
	return ret;
}

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	int z = count(s.begin(), s.end(), '0');
	int o = n - z;
	ll ans = 0;
	while (z > 0 and o > 1) {
		add(ans, get(z, o - 1));
		z--;
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);

	fact[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = fact[i - 1] * i % mod;
	}
	ifact[N - 1] = poww(fact[N - 1], mod - 2);
	for (int i = N - 2; i >= 0; --i) {
		ifact[i] = ifact[i + 1] * (i + 1) % mod;
	}

	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		solve();
	}
}