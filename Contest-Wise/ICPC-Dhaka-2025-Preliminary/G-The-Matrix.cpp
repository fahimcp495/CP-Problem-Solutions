#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int IDX = 30;

void solve() {
	int n, m; cin >> n >> m;
	int a[n][m];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}

	vector<int> row(n), col(m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			row[i] ^= a[i][j];
			col[j] ^= a[i][j];
		}
	}

	ll sum = accumulate(row.begin(), row.end(), 0ll);
	sum += accumulate(col.begin(), col.end(), 0ll);

	ll ans = sum;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			ll bad = 0;
			for (int idx = IDX - 1; idx >= 0; --idx) {
				if ((row[i] >> idx & 1) and (col[j] >> idx & 1)) {
					bad += 2 << idx;
				}
			}
			ll now = sum - bad;
			ans = min(ans, now);
		}
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		solve();
	}
}