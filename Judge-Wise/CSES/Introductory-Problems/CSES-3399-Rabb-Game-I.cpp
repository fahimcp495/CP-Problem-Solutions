#include <bits/stdc++.h>
using namespace std;

void solve () {
	int n, a, b; cin >> n >> a >> b;

	if (a + b > n or (a and !b) or (!a and b)) {
		cout << "NO\n";
		return ;
	}

	vector<int> first(n), second(n);
	iota(first.begin(), first.end(), 1);
	iota(second.begin(), second.end(), 1);
	rotate(first.begin(), first.begin() + b, first.begin() + a + b);
	cout << "YES\n";
	for (int i = 0; i < n; ++i) {
		cout << first[i] << " \n"[i == n - 1];
	}
	for (int i = 0; i < n; ++i) {
		cout << second[i] << " \n"[i == n - 1];
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);

	int t; cin >> t;
	while (t--) {
		solve();
	}
}