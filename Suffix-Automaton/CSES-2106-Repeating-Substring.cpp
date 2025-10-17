// Problem link: https://cses.fi/problemset/task/2106

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int len[2 * N], lnk[2 * N], last, sz = 1;
unordered_map<char, int> to[2 * N];

int deg[2 * N], cnt[2 * N], focc[2 * N];

void init(int n) {
  fill(deg, deg + 2 * n, 0);
  fill(cnt, cnt + 2 * n, 0);
  fill(focc, focc + 2 * n, -1);
  while (sz) to[--sz].clear();
  lnk[0] = -1, last = 0, sz = 1;
}

void add (char c, int i) {
  int cur = sz++;
  len[cur] = len[last] + 1;
  cnt[cur] = 1;
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

void solve () {
  string s; cin >> s;
  int n = s.size();
  init(n);
  for (int i = 0; i < n; ++i) {
    add(s[i], i + 1);
  }
  build();
  int idx, mx_len = 0;
  for (int u = 1; u < sz; ++u) {
    if (cnt[u] <= 1) continue;
    if (len[u] > mx_len) {
      mx_len = len[u];
      idx = focc[u] - len[u];
    }
  }

  if (mx_len == 0) cout << "-1\n";
  else cout << s.substr(idx, mx_len) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int t = 1;
  while (t--) {
    solve();
  }
}