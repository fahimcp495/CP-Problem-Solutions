#include<bits/stdc++.h>
using namespace std;

const int N = 8;

vector<vector<int>> valids;

void backtrack(vector<int> &idx, int i) {
  if (i == N) {
    valids.push_back(idx);
    return ;
  }

  for (int j = 0; j < N; ++j) {
    int ok = 1;
    for (int ii = 0; ii < i; ++ii) {
      int jj = idx[ii];
      if (j == jj or i + j == ii + jj  or i - j == ii - jj) {
        ok = 0;
      }
    }


    if (ok) {
      idx.push_back(j);
      backtrack(idx, i + 1);
      idx.pop_back();
    }
  }
}

void pre() {
  vector<int> idx;
  backtrack(idx, 0);
}

int dp[N][1<<N];

vector<array<int, 2>> q;

int rec(vector<int> &col, int i, int mask) {
  if (i == N) {
    return 0;
  }
  if (dp[i][mask] != -1) {
    return dp[i][mask];
  }

  int &ret = dp[i][mask];
  ret = 2 * N;
  int j = col[i];
  for (int k = 0; k < N; ++k) {
    if (!(mask & (1 << k))) {
      int ii = q[k][0], jj = q[k][1];
      if (ii == i and jj == j) {
        ret = min(ret, rec(col, i + 1, mask | (1 << k)));
      }
      else if (ii == i or jj == j or i + j == ii + jj or i - j == ii - jj) {
        ret = min(ret, rec(col, i + 1, mask | (1 << k)) + 1);
      }
      else {
        ret = min(ret, rec(col, i + 1, mask | (1 << k)) + 2);
      }
    }
  }
  return ret;
}

void solve() {
  vector<string> s(N);
  for (auto &si: s) {
    cin >> si;
  }

  q.clear();
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (s[i][j] == 'q') {
        q.push_back({i, j});
      }
    }
  }

  int ans = 2 * N;

  for (auto &valid: valids) {
    memset(dp, -1, sizeof(dp));
    ans = min(ans, rec(valid, 0, 0));
  }

  cout << ans << '\n';
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  pre();

  int t;  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case " << i << ": ";
    solve();
  }
}

