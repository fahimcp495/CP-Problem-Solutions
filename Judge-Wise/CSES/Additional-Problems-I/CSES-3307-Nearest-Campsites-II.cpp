#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const int X = 1e6;
const int INF = 1e8;
 
int st[2][4 * X];
 
void update(int i, array<int, 2> x, int u = 1, int s = 1, int e = X) {
    if (s == e) {
        st[0][u] = min(st[0][u], x[0]);
        st[1][u] = min(st[1][u], x[1]);
        return ;
    }
    int v = u << 1, w = v | 1, m = (s + e) >> 1;
    if (i <= m) update(i, x, v, s,m);
    else update(i, x, w, m + 1, e);
    st[0][u] = min(st[0][v], st[0][w]);
    st[1][u] = min(st[1][v], st[1][w]);
}
 
int rmq(int idx, int l, int r, int u = 1, int s = 1, int e = X) {
    if (e < l or r < s) return INF;
    if (l <= s and e <= r) return st[idx][u];
    int v = u << 1, w = v | 1, m = (s + e) >> 1;
    return min(rmq(idx, l, r, v, s, m), rmq(idx, l, r, w, m + 1, e));
}
 
void solve() {
    int n, m; cin >> n >> m;
    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; ++i) {
        auto &[x, y, idx] = a[i];
        cin >> x >> y;
        idx = i;
    }
    vector<array<int, 3>> b(m);
    for (int i = 0; i < m; ++i) {
        auto &[x, y, idx] = b[i];
        cin >> x >> y;
        idx = i;
    }
 
    auto init = [&] {
        fill(st[0], st[0] + 4 * X, INF);
        fill(st[1], st[1] + 4 * X, INF);
    };
 
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> dis(m, INF);
 
    init();
    int i = 0, j = 0;
    while (j < m) {
        while (i < n and a[i][0] <= b[j][0]) {
            auto [x, y, idx] = a[i];
            update(y, {-x - y, -x + y});
            i++;
        }
        auto [x, y, idx] = b[j];
        int sum = x + y;
        int mn = rmq(0, 1, y);
        dis[idx] = min(dis[idx], sum + mn);
 
        sum = x - y;
        mn = rmq(1, y, X);
        dis[idx] = min(dis[idx], sum + mn);
        j++;
    }
 
    init();
    i = n - 1, j = m - 1;
    while (j >= 0) {
        while (i >= 0 and a[i][0] >= b[j][0]) {
            auto [x, y, idx] = a[i];
            update(y, {x - y, x + y});
            i--;
        }
        auto [x, y, idx] = b[j];
        int sum = -x + y;
        int mn = rmq(0, 1, y);
        dis[idx] = min(dis[idx], sum + mn);
 
        sum = -x - y;
        mn = rmq(1, y, X);
        dis[idx] = min(dis[idx], sum + mn);
        j--;
    }
 
    for (auto d: dis) {
        cout << d << " ";
    }
    cout << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    solve();
}