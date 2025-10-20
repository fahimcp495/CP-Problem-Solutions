// Problem link: https://cses.fi/problemset/task/2105

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;

int len[2 * N], lnk[2 * N], last, sz = 1;
unordered_map<char, int> to[2 * N];

ll dp[2 * N];

void init(int n) {
  fill(dp, dp + 2 * n, -1);
  while (sz) to[--sz].clear();
  lnk[0] = -1, last = 0, sz = 1;
}

void add (char c) {
  int cur = sz++;
  len[cur] = len[last] + 1;
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

ll dfs (int u, int p) {
  if (dp[u] != -1) return dp[u];
  dp[u] = 1;
  for (auto [c, v]: to[u]) {
    if (v == p) continue;
    dp[u] += dfs(v, u);
  }
  return dp[u];
}

void solve () {
  string s; cin >> s;
  int n = s.size();
  init(n);
  for (auto c: s) {
    add(c);
  }
  cout << dfs(0, 0) - 1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int t = 1;
  while (t--) {
    solve();
  }
}