// Problem link: https://cses.fi/problemset/task/2104

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;

int len[2 * N], lnk[2 * N], last, sz = 1;
unordered_map<char, int> to[2 * N];

int focc[2 * N];

void init(int n) {
  while (sz) to[--sz].clear();
  lnk[0] = -1, last = 0, sz = 1;
}

void add (char c, int i) {
  int cur = sz++;
  len[cur] = len[last] + 1;
  focc[cur] = i;
  int u = last;
  last = cur;
  while (u != -1 and !to[u].count(c)) {
    to[u][c] = cur;
    u = lnk[u];
  }
  if (u == -1) {
    lnk[cur] = 0;
  }
  else {
    int v = to[u][c];
    if (len[u] + 1 == len[v]) {
      lnk[cur] = v;
    }
    else {
      int w = sz++;
      len[w] = len[u] + 1;
      lnk[w] = lnk[v], to[w] = to[v];
      focc[w] = focc[v];
      while (u != -1 and to[u][c] == v) {
        to[u][c] = w, u = lnk[u];
      }
      lnk[cur] = lnk[v] = w;
    }
  }
}

ll get_focc (string &p) {
  int u = 0;
  for (auto c: p) {
    if (!to[u].count(c)) return -1;
    u = to[u][c];
  }
  return focc[u];
}

void solve () {
  string s; cin >> s;
  int n = s.size();
  init(n);
  for (int i = 0; i < n; ++i) {
    add(s[i], i + 1);
  }
  int q; cin >> q;
  while (q--) {
    string t; cin >> t;
    int idx = get_focc(t);
    if (idx == -1) cout << "-1\n";
    else cout << idx - t.size() + 1 << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int t = 1;
  while (t--) {
    solve();
  }
}