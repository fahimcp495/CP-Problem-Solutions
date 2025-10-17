// Problem link: https://open.kattis.com/problems/stringmultimatching

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 5;

int len[2 * N], lnk[2 * N], last, sz = 1;
unordered_map<char, int> to[2 * N];

int deg[2 * N], focc[2 * N];
vector<int> childs[2 * N];

void init(int n) {
  fill(deg, deg + sz, 0);
  fill(focc, focc + sz, 0);
  while (sz) to[--sz].clear(), childs[sz].clear();
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
      while (u != -1 and to[u][c] == v) {
        to[u][c] = w, u = lnk[u];
      }
      lnk[cur] = lnk[v] = w;
    }
  }
}

int find (string &p) {
  int u = 0;
  for (auto c: p) {
    if (!to[u].count(c)) return -1;
    u = to[u][c];
  }
  return u;
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
    childs[v].push_back(u);
    deg[v]--;
    if (!deg[v]) q.push(v);
  }
}

void dfs (int u, int p, vector<int> &pos) {
  if (focc[u] != 0) pos.push_back(focc[u]);
  for (auto v: childs[u]) {
    if (v == p) continue;
    dfs(v, u, pos);
  }
}

void solve () {
  int k;
  while (cin >> k) {
    cin >> ws;
    vector<string> p(k);
    for (auto &pi: p) {
      getline(cin, pi);
    }
    string s; getline(cin, s);
    int n = s.size();
    init(n);
    for (int i = 0; i < n; ++i) {
      add(s[i], i + 1);
    }
    for (int u = 0; u < sz; ++u) {
      for (auto [c, v]: to[u]) {
      }
    }
    build();
    for (auto &pi: p) {
      int u = find(pi);
      vector<int> pos;
      if (u != -1) {
        dfs(u, u, pos);
      }
      sort(pos.begin(), pos.end());
      for (auto idx: pos) {
        cout << idx - pi.size() << " ";
      }
      cout << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int t = 1;
  while (t--) {
    solve();
  }
}