#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 5;

int n, a[N];

struct Node {
  ll mx = 0, mxL = 0, mxR = 0, mxLR = 0;
} st[4 * N];

Node merge (Node u, Node v) {
  if (u.mx == 0) return v;
  if (v.mx == 0) return u;
  Node ret;
  ret.mx = max(u.mx + v.mxL, u.mxR + v.mx);
  ret.mxL = max(u.mxLR + v.mx, u.mxL + v.mxL);
  ret.mxR = max(u.mxR + v.mxR, u.mx + v.mxLR);
  ret.mxLR = max(u.mxLR + v.mxR, u.mxL + v.mxLR);
  return ret;
}

void assign (int i, int x, int u = 1, int s = 0, int e = n - 1) {
  if (s == e) {
    st[u].mx = x;
    return ;
  }
  int v = u << 1, w = v | 1, m = (s + e) >> 1;
  if (i <= m) assign(i, x, v, s, m);
  else assign(i, x, w, m + 1, e);
  st[u] = merge(st[v], st[w]);
}

Node rquery (int l, int r, int u = 1, int s = 0, int e = n - 1) {
  if (e < l or r < s) return Node();
  if (l <= s and e <= r) return st[u];
  int v = u << 1, w = v | 1, m = (s + e) >> 1;
  auto res = merge(rquery(l, r, v, s, m), rquery(l, r, w, m + 1, e));

  return res;
}

vector<int> adj[N];
int par[N], dep[N], sz[N], hc[N];

void dfs (int u) {
  sz[u] = 1, hc[u] = -1;
  for (auto v: adj[u]) {
    dep[v] = dep[u] + 1;
    dfs(v);
    sz[u] += sz[v];
    if (hc[u] == -1 or sz[hc[u]] < sz[v]) hc[u] = v;
  }
}

int idx, in[N], hd[N];

void hld (int u) {
  in[u] = idx++;
  if (hd[u] == -1) hd[u] = u;
  if (hc[u] != -1) hd[hc[u]] = hd[u], hld(hc[u]);
  for (auto v: adj[u]) {
    if (v != hc[u]) hld(v);
  }
}

ll pquery (int u, int v) {
  Node res_u = Node(), res_v = Node();
  while (hd[u] != hd[v]) {
    if (dep[hd[u]] > dep[hd[v]]) {
      auto res = rquery(in[hd[u]], in[u]);
      res_u = merge(res, res_u);
      u = par[hd[u]];
    }
    else {
      auto res = rquery(in[hd[v]], in[v]);
      res_v = merge(res, res_v);
      v = par[hd[v]];
    }
  }

  if (dep[u] < dep[v]) {
    auto res = rquery(in[u], in[v]);
    res_v = merge(res, res_v);
  }
  else {
    auto res = rquery(in[v], in[u]);
    res_u = merge(res, res_u);
  }

  swap(res_u.mxL, res_u.mxR);
  auto res = merge(res_u, res_v);
  return res.mx;
}

void solve () {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int u = 1; u < n; ++u) {
    cin >> par[u]; par[u]--;
    adj[par[u]].push_back(u);
  }
  dfs(0);
  fill(hd, hd + n, -1);
  hld(0);

  for (int u = 0; u < n; ++u) {
    assign(in[u], a[u]);
  }

  int q; cin >> q;
  while (q--) {
    int t; cin >> t;
    if (t == 1) {
      int u, x; cin >> u >> x; u--;
      assign(in[u], x);
    }
    else {
      int u, v; cin >> u >> v; u--, v--;
      cout << pquery(u, v) << "\n";
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