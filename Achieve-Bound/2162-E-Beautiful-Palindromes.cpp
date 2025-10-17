// Problem link: https://codeforces.com/contest/2162/problem/E

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve () {
  int n, k; cin >> n >> k;
  set<int> absent;
  for (int i = 1; i <= n; ++i) {
    absent.insert(i);
  }
  vector<int> a(n);
  for (auto &ai: a) {
    cin >> ai;
    if (absent.count(ai)) {
      absent.erase(ai);
    }
  }

  while (k > 0 and !absent.empty()) {
    a.push_back(*absent.begin());
    absent.erase(absent.begin());
    k--;
  }

  for (int i = 0; i < a.size() - 1; ++i) {
    assert(a[i] != a.back());
  }
  int z = a.back();
  int y = a[a.size() - 2];
  int x;
  for (int i = a.size() - 3; i >= 0; --i) {
    if (a[i] != y) {
      x = a[i];
      break;
    }
  }

  while (k--) {
    a.push_back(x);
    swap(x, y);
    swap(y, z);
  }

  for (int i = n; i < a.size(); ++i) {
    cout << a[i] << " ";
  }
  cout << "\n";

}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}