#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define eb  emplace_back

#define dbg(a)  cerr << #a << ": " << a << "\n"

struct AC {
  const int A = 26;
  vector<vector<int>> nxt, idx;
  vector<int> lnk, out_lnk, ans;
  AC () { newNode(); }
  int newNode() {
    nxt.eb(A, 0), idx.eb(0);
    lnk.eb(0), out_lnk.eb(0), ans.eb(0);
    return nxt.size() - 1;
  }

  void clear () {
    nxt.clear(), idx.clear();
    lnk.clear(), out_lnk.clear(), ans.clear();
    newNode();
  }

  void add (string p, int i) {
    int u = 0;
    for (auto c: p) {
      int id = c - 'a';
      if (!nxt[u][id])  nxt[u][id] = newNode();
      u = nxt[u][id];
    }
    idx[u].eb(i);
  }

  void build () {
    queue<int> q;  q.push(0);
    while (!q.empty()) {
      int u = q.front();  q.pop();
      for (int i = 0; i < A; ++i) {
        int v = nxt[u][i];
        if (!v)  nxt[u][i] = nxt[lnk[u]][i];
        else {
          lnk[v] = u? nxt[lnk[u]][i]: 0;
          out_lnk[v] = idx[lnk[v]].empty()? out_lnk[lnk[v]]: lnk[v];
          q.push(v);
        }
      }
    }
  }

  void trav (string T) {
    int u = 0;
    for (auto c: T) {
      int id = c - 'a';
      if (!nxt[u][id])  u = lnk[u];
      if (nxt[u][id])  u = nxt[u][id];
      for (auto i: idx[u]) {
        ans[i]++;
      }
      int x = out_lnk[u];
      while (x) {
        for (auto i: idx[x]) {
          ans[i]++;
        }
        x = out_lnk[x];
      }
    }
  }
};

void solve() {
  int n;  cin >> n;
  string T;  cin >> T;
  vector<string> p(n);
  for (auto &pi: p) {
    cin >> pi;
  }

  AC ac;
  for (int i = 0; i < n; ++i) {
    ac.add(p[i], i);
  }

  ac.build();
  ac.trav(T);

  for (int i = 0; i < n; ++i) {
    cout << ac.ans[i] << "\n";
  }
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int tc;  cin >> tc;
  for (int t = 1; t <= tc; ++t) {
    cout << "Case " << t << ":\n";
    solve();
  }
}
