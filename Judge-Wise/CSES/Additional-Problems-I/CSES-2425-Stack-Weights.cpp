#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
const int N = 2e5+5;
 
int n;
int mn[4 * N], mx[4 * N], prop[4 * N];
 
void add(int l, int r, int x, int u = 1, int s = 0, int e = n - 1) {
  if (e < l or r < s)  return ;
  if (l <= s and e <= r) {
    prop[u] += x;
    mn[u] += x;
    mx[u] += x;
    return ;
  }
  int v = u << 1, w = u << 1 | 1, m = (s + e) >> 1;
  prop[v] += prop[u], mn[v] += prop[u], mx[v] += prop[u];
  prop[w] += prop[u], mn[w] += prop[u], mx[w] += prop[u];
  prop[u] = 0;
  add(l, r, x, v, s, m);
  add(l, r, x, w, m + 1, e);
  mn[u] = min(mn[v], mn[w]);
  mx[u] = max(mx[v], mx[w]);
}
 
void solve () {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int c, s;  cin >> c >> s;  c--;
    if (s == 1)  add(0, c, -1);
    else  add(0, c, 1);
    if (mn[1] < 0 and mx[1] > 0) {
      cout << "?\n";
    }
    else if (mn[1] < 0) {
      cout << ">\n";
    }
    else {
      cout << "<\n";
    }
  }
 
}
 
int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int tc = 1;
  // cin >> tc;
  for (int t = 1; t <= tc; ++t) {
    solve();
  }
}
