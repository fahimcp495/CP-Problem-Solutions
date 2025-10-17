// Problem link: https://cses.fi/problemset/task/2103

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 6;

int len[2 * N], lnk[2 * N], last, sz = 1;
unordered_map<char, int> to[2 * N];

int deg[2 * N];
ll cnt[2 * N];

void init(int n) {
  fill(deg, deg + sz, 0);
  fill(cnt, cnt + sz, 0);
  while (sz) to[--sz].clear();
  lnk[0] = -1, last = 0, sz = 1;
}

void add (char c) {
  int cur = sz++;
  len[cur] = len[last] + 1;
  cnt[cur] = 1;
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
      while (u != -1 and to[u][c] == v) {
        to[u][c] = w, u = lnk[u];
      }
      lnk[cur] = lnk[v] = w;
    }
  }
}

void build() {
  deg[0] = 1;
  for (int u = 1; u < sz; ++u) {
    deg[lnk[u]]++;
  }
  queue<int> q;
  for (int u = 0; u < sz; ++u) {
    if (!deg[u]) q.push(u);
  }
  while (!q.empty()) {
    int u = q.front(); q.pop();
    int v = lnk[u];
    cnt[v] += cnt[u];
    deg[v]--;
    if (!deg[v]) q.push(v);
  }
}

ll count (string &p) {
  int u = 0;
  for (auto c: p) {
    if (!to[u].count(c)) return 0;
    u = to[u][c];
  }
  return cnt[u];
}

void solve () {
  string s; cin >> s;
  int n = s.size();
  init(n);
  for (auto c: s) {
    add(c);
  }
  build();
  int q; cin >> q;
  while (q--) {
    string t; cin >> t;
    cout << count(t) << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int t = 1;
  while (t--) {
    solve();
  }
}