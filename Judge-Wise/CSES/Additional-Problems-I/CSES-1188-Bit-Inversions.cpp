#include<bits/stdc++.h>
using namespace std;
 
const int N = 2e5+5;
 
int n;
 
array<int, 3> st[2][4 * N];
 
void assign(int i, int x, int u = 1, int s = 0, int e = n - 1) {
  if (s == e) {
    st[x][u] = {1, 1, 1};
    st[x ^ 1][u] = {0, 0, 0};
    return ;
  }
 
  int v = 2 * u, w = 2 * u + 1, m = (s + e) / 2;
  if (i <= m)  assign(i, x, v, s, m);
  else  assign(i, x, w, m + 1, e);
 
  int k = 2;
  while (k--) {
    st[k][u][0] = st[k][v][0] + ((st[k][v][0] == m - s + 1)? st[k][w][0]: 0);
    st[k][u][1] = st[k][w][1] + ((st[k][w][1] == e - m)? st[k][v][1]: 0);
    st[k][u][2] = max({st[k][v][2], st[k][v][1] + st[k][w][0], st[k][w][2]});
  }
}
 
int main(){
  ios::sync_with_stdio(0), cin.tie(0);
 
  string s;  cin >> s;
  n = s.size();
  for (int i = 0; i < n; ++i) {
    assign(i, s[i] - '0');
  }
 
  int q;  cin >> q;
  while (q--) {
    int i; cin >> i; --i;
    s[i] ^= 1;
    assign(i, s[i] - '0');
    cout << max(st[0][1][2], st[1][1][2]) << " ";
  }
}