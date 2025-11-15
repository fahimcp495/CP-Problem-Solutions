#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const int N = 2e6 + 6;
const int C = 26;
 
int len[2 * N], lnk[2 * N], last, sz = 1;
array<int, C> to[2 * N];
 
void init() {
  lnk[0] = -1;
}
 
void add (int c) {
  int cur = sz++;
  len[cur] = len[last] + 1;
  int u = last;
  last = cur;
  while (u != -1 and !to[u][c]) {
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
        add(c - 'a');
    }
    for (auto c: s) {
        add(c - 'a');
    }
 
    string ans;
    int u = 0;
    while (n--) {
        for (int c = 0; c < C; ++c) {
            if (to[u][c]) {
                ans += 'a' + c;
                u = to[u][c];
                break;
            }
        }
    }
    cout << ans << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
 
    int t = 1;
    while (t--) {
        solve();
    }
}