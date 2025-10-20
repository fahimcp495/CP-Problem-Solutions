#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 50004;

int len[2 * N], lnk[2 * N], last, sz = 1;
unordered_map<char, int> to[2 * N];
int focc[2 * N];

void init() {
  while (sz) {
    to[--sz].clear();
  }
  lnk[0] = -1, last = 0, sz = 1;
}

void add (char c, int i) {
  int cur = sz++;
  len[cur] = len[last] + 1;
  focc[cur] = i + 1;
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
      len[w] = len[u] + 1, lnk[w] = lnk[v], to[w] = to[v];
      focc[w] = focc[v];
      while (u != -1 and to[u][c] == v) {
        to[u][c] = w, u = lnk[u];
      }
      lnk[cur] = lnk[v] = w;
    }
  }
}

ll dp[2 * N];

ll dfs (int u) {
  if (dp[u] != -1) return dp[u];
  dp[u] = 1;
  for (auto [c, v]: to[u]) {
    dp[u] += dfs(v);
  }
  return dp[u];
}

auto get (string s) {
  int n = s.size();
  vector<int> pi(n);
  for (int k = 0, i = 1; i < n; ++i) {
    if (s[i] == s[k]) pi[i] = ++k;
    else if (k == 0) pi[i] = 0;
    else k = pi[k - 1], --i;
  }
  return pi;
}

void solve () {
  init();
  string s; cin >> s;
  string t; cin >> t;
  int n = s.size();
  int m = t.size();
  for (int i = 0; i < n; ++i) {
    add(s[i], i);
  }
  auto pi = get(t + '#' + s);
  vector<int> L(n + 1, -n);
  for (int i = 0; i < n; ++i) {
    if (pi[m + 1 + i] == m) L[i + 1] = i + 1;
    else L[i + 1] = L[i];
  }

  fill(dp, dp + sz, -1);
  ll ans = dfs(0) - 1;

  vector<int> adj[sz];
  for (int u = 1; u < sz; ++u) {
    adj[lnk[u]].push_back(u);
  }

  int u = 0;
  for (auto c: t) {
    if (!to[u].count(c)) {
      u = -1;
      break;
    }
    u = to[u][c];
  }
  if (u != -1) {
    ans -= (len[u] - max(m - 1, len[lnk[u]])) * dfs(u);
    vector<int> vis(sz);
    queue<int> q; q.push(u);
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (auto v: adj[u]) {
        if (!vis[v]) {
          vis[v] = 1;
          int i = focc[v];
          assert(L[i] == i);
          int j = i - m;
          int l = max(i - len[v] + 1, L[i - 1] - m + 2);
          int r = i - len[lnk[v]];
          int cnt = r - l + 1;
          cnt = max(cnt, 0);
          ans -= cnt * dfs(v);
          q.push(v);
        }
      }
    }
  }
  cout << ans << "\n";
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case " << i << ": ";
    solve();
  }
  return 0;
}