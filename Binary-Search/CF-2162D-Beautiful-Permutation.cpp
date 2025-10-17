// Problem link: https://codeforces.com/contest/2162/problem/D

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ask (int t, int l, int r) {
  cout << t << " " << l << " " << r << endl;
  int rep; cin >> rep;
  return rep;
}

void print_res (int l, int r) {
  cout << "! " << l << " " << r << endl;
}

void solve () {
  int n; cin >> n;
  int len = ask(2, 1, n) - n * (n + 1) / 2;
  int lo = 1, hi = n;
  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    int bad = ask(2, 1, mid) - ask(1, 1, mid);
    if (bad == len) hi = mid - 1;
    else lo = mid + 1;
  }
  print_res(lo - len + 1, lo);
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}