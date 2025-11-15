#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const int N = 1e6 + 6;
 
int len[2 * N], lnk[2 * N], last, sz = 1;
map<char, int> to[2 * N];
int suf[2 * N];
 
void init() {
  lnk[0] = -1;
}
 
void add (char c) {
  int cur = sz++;
  len[cur] = len[last] + 1;
  int u = last;
  last = cur;
  while (u != -1 and to[u].find(c) == to[u].end()) {
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
 
void solve () {
    string s; cin >> s;
    int n = s.size();
 
    init();
    for (auto c: s) {
        add(c);
    }

    while (last != -1) {
        suf[last] = 1;
        last = lnk[last];
    }

    int u = 0;
    for (int i = 0; i < n - 1; ++i) {
        u = to[u][s[i]];
        if (suf[u]) {
            cout << i + 1 << " ";
        }
    }
    cout << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
 
    int t = 1;
    while (t--) {
        solve();
    }
}