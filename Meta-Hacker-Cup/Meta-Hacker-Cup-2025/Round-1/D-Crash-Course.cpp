#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve () {
  int n; cin >> n;
  string s; cin >> s;
  s += 'A';
  n++;

  int sum = 0;
  int a = 0, b = 0;
  for (int i = n - 2; i >= 0; --i) {
    if (s[i] == s[i + 1]) {
      if (s[i] == 'A') sum++;
      else sum--;
    }
    if (sum > 0) {
      cout << "Alice\n";
      return ;
    }
  }
  cout << "Bob\n";
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int t; cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}