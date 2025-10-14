// Problem link: https://codeforces.com/contest/2149/problem/G

#include <bits/stdc++.h>
using namespace std;
using ll = long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand (int l, int r) {
	return rng() % (r - l + 1) + l;
}

void solve () {
	int n, q; cin >> n >> q;
	vector<int> a(n);
	for (auto &ai: a) {
		cin >> ai;
	}
	vector<int> all = a;
	sort(all.begin(), all.end());
	all.erase(unique(all.begin(), all.end()), all.end());
	for (auto &ai: a) {
		ai = lower_bound(all.begin(), all.end(), ai) - all.begin();
	}
	vector<int> pos[n];
	for (int i = 0; i < n; ++i) {
		pos[a[i]].push_back(i);
	}

	while (q--) {
		int l, r; cin >> l >> r; l--, r--;
		int len = r - l + 1;
		int itr = 50;
		int x = -1, y = -1;
		while (itr--) {
			int idx = rand(l, r);
			if (x == all[a[idx]]) continue;
			int cnt = upper_bound(pos[a[idx]].begin(), pos[a[idx]].end(), r) - lower_bound(pos[a[idx]].begin(), pos[a[idx]].end(), l);
			if (cnt > len / 3) {
				if (x == -1) x = all[a[idx]];
				else {
					y = all[a[idx]];
					if (x > y) swap(x, y);
					break;
				}
			}
		}
		if (x == -1) cout << "-1\n";
		else {
			cout << x;
			if (y != -1) cout << " " << y;
			cout << "\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}
