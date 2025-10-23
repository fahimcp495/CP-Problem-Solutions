#include <bits/stdc++.h>
using namespace std;

const int N = 1003;

int di[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dj[] = {1, 2, 2, 1, -1, -2, -2, -1};

int dis[N][N];

void solve () {
    int n; cin >> n;
    dis[0][0] = 0;
    queue<array<int, 2>> q; q.push({0, 0});
    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for (int dir = 0; dir < 8; ++dir) {
            int ii = i + di[dir];
            int jj = j + dj[dir];
            if (ii >= 0 and ii < n and jj >= 0 and jj < n and dis[ii][jj] == -1) {
                dis[ii][jj] = dis[i][j] + 1;
                q.push({ii, jj});
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << dis[i][j] << " \n"[j == n - 1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    memset(dis, -1, sizeof(dis));

    int t = 1;
    while (t--) {
        solve();
    }
}