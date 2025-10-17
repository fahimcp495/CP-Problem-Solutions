// Problem link: https://cses.fi/problemset/task/2109

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;

int len[2 * N], lnk[2 * N], last, sz = 1;
map<char, int> to[2 * N];

vector<int> nodes[N];
int cnt[2 * N];
ll dp[2 * N];

void init(int n) {
  fill(cnt, cnt + sz, 0);
  fill(dp, dp + sz,0);
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

void build(int n) {
  for (int u = 0; u < sz; ++u) {
    nodes[len[u]].emplace_back(u);
  }
  for (int l = n; l > 0; --l) {
    for (auto u: nodes[l]) {
      cnt[lnk[u]] += cnt[u];
    }
  }
 
  for (int l = n; l >= 0; --l) {
    for (auto u: nodes[l]) {
      dp[u] = cnt[u];
      for (auto [c, v]: to[u]) {
        dp[u] += dp[v];
      }
    }
  }
}

string kth (ll k) {
  string s;
  int u = 0;
  while (k > 0) {
    for (auto [c, v]: to[u]) {
      if (k > dp[v]) {
        k -= dp[v];
      }
      else {
        k -= cnt[v];
        s += c;
        u = v;
        break;
      }
    }
  }
  return s;
}

void solve () {
  string s; cin >> s;
  ll k; cin >> k;
  int n = s.size();
  init(n);
  for (auto c: s) {
    add(c);
  }
  build(n);
  cout << kth(k) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int t = 1;
  while (t--) {
    solve();
  }
}