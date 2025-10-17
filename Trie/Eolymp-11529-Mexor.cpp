// Problem link: https://eolymp.com/en/problems/11529

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3e5 + 5;
const int IDX = 20;

int trie[N * IDX][2], cnt[N * IDX], lz[N * IDX], tot = 1;

void add (int x) {
  int u = 1;
  for (int idx = IDX - 1; idx >= 0; --idx) {
    int f = x >> idx & 1;
    if (!trie[u][f]) trie[u][f] = ++tot;
    u = trie[u][f];
    cnt[u]++;
  }
}

int xor_mex (int x) {
  int mex = 0;
  int u = 1;
  for (int idx = IDX - 1; idx >= 0; --idx) {
    int f = x >> idx & 1;
    int v = trie[u][f];
    int w = trie[u][!f];
    if (cnt[v] < (1 << idx)) {
      if (v == 0) break;
      u = v;
    }
    else {
      mex |= 1 << idx;
      if (w == 0) break;
      u = w;
    }
  }
  return mex;
}

void solve () {
  int n, m; cin >> n >> m;
  vector<int> a(n);
  for (auto &ai: a) {
    cin >> ai;
  }
  set<int> st(a.begin(), a.end());
  for (auto x: st) {
    add(x);
  }
  int y = 0;
  while (m--) {
    int x; cin >> x;
    y ^= x;
    cout << xor_mex(y) << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int t = 1;
  while (t--) {
    solve();
  }
}