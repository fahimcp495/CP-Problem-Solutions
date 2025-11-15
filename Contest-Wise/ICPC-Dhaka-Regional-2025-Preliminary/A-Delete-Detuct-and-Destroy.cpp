#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e6 + 6;

ll cnt[N];

void solve() {
	int n; cin >> n;
	string s; cin >> s;

	int sum = 0;
	set<int> st = {-1};
	for (int i = 0; i < n; ++i) {
		if (s[i] != '0') {
			st.insert(i);
		}
		sum = (sum + (s[i] - '0')) % 9;
	}

	int q; cin >> q;
	while (q--) {
		int i; cin >> i; i = n - i;
		char d; cin >> d;
		if (s[i] != '0') st.erase(i);
		sum = (sum - (s[i] - '0') + 9) % 9;
		s[i] = d;
		if (s[i] != '0') st.insert(i);
		sum = (sum + (s[i] - '0')) % 9;
		int k = n - 1 - *st.rbegin();
		if (k == n) {
			cout << "0\n";
			continue;
		}
		if (*st.rbegin() == n - 1 and st.size() == 2) {
			if (s.back() == '9') {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
			continue ;
		}

		ll ans = cnt[k];
		if (sum == 0) {
			ans = 2ll * ans % mod;
		}
		cout << ans << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);

	cnt[0] = 1;
	for (int i = 1; i < N; ++i) {
		cnt[i] = (1ll * cnt[i - 1] * 10 + 1) % mod;
	}

	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; ++i) {
		solve();
	}
}