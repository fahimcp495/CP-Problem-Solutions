// Problem link: https://codeforces.com/contest/2145/problem/E

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e6 + 6;

int ac, dr, n, a[N], d[N], m;
int st[4 * N], lz[4 * N];
 
void push (int u){
  int v = u << 1, w = v | 1;
  st[v] += lz[u], lz[v] += lz[u];
  st[w] += lz[u], lz[w] += lz[u];
  lz[u] = 0;
}

void add(int l, int r, int x, int u = 1, int s = 0, int e = N - 1){
  if (e < l or r < s)  return  ;
  if (l <= s and e <= r){
    st[u] += x, lz[u] += x;
    return ;
  }
  push(u);
  int v = u << 1, w = v | 1, m = (s + e) >> 1;
  add(l, r, x, v, s, m);
  add(l, r, x, w, m + 1, e);
  st[u] = min(st[v], st[w]);
}

int query (int u = 1, int s = 0, int e = N - 1) {
    if (s == e) return s;
    int v = u << 1, w = v | 1, m = (s + e) >> 1;
    push(u);
    if (st[v] <= 0) return query(v, s, m);
    else return query(w, m + 1, e);
}

void solve() {
    cin >> ac >> dr;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    for (int i = 1; i < N; ++i) {
        add(i, N - 1, -1);
    }
    for (int i = 0; i < n; ++i) {
        int val = max(a[i] - ac, 0) + max(d[i] - dr, 0);
        add(val, N - 1, 1);
    }
    cin >> m;
    while (m--) {
        int i; cin >> i; i--;
        int val = max(a[i] - ac, 0) + max(d[i] - dr, 0);
        add(val, N - 1, -1);
        cin >> a[i] >> d[i];
        val = max(a[i] - ac, 0) + max(d[i] - dr, 0);
        add(val, N - 1, 1);
        cout << query() << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int t = 1;
    while (t--) {
        solve();
    }
}