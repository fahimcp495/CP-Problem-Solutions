#include<bits/stdc++.h>
using namespace std;

const int N = 15, INF = 1e9;

int n, m;
int len[N][N];

int dp[1<<N];

int rec(int mask) {
  if (mask == 0) {
    return 0;
  }

  int &ret = dp[mask];

  if (ret != -1) {
    return ret;
  }

  ret = INF;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ret = min(ret, len[i][j] + rec(mask ^ (1 << i) ^ (1 << j)));
    }
  }

  return ret;
}

void solve() {
  cin >> n >> m;
  for (int u = 0; u < n; ++u) {
    for (int v = 0; v < n; ++v) {
      len[u][v] = INF;
    }
  }

  int ans = 0;
  int mask = 0;
  for (int e = 0; e < m; ++e) {
    int u, v;  cin >> u >> v;  u--, v--;
    int c;  cin >> c;
    len[u][v] = min(len[u][v], c);
    ans += c;
    mask ^= (1 << u);
    mask ^= (1 << v);
  }

  memset(dp, -1, sizeof(dp));

  cout << ans + rec(mask) << '\n';

}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int t;  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case " << i << ": ";
    solve();
  }
}