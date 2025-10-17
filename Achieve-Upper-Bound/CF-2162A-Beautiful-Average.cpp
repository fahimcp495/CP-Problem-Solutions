// Problem link: https://codeforces.com/contest/2162/problem/A

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve () {
  int n; cin >> n;
  vector<int> a(n);
  for (auto &ai: a) {
    cin >> ai;
  }
  cout << *max_element(a.begin(), a.end()) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}