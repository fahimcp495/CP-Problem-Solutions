// Problem link: https://codeforces.com/contest/1324/problem/F

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;

int n;
int a[N];
vector<int> adj[N];
int down[N], up[N];

void dfs (int u, int p) {
    down[u] = a[u];
    for (auto v: adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        down[u] += max(down[v], 0);
    }
}

void dfs2 (int u, int p) {
    int k = adj[u].size();
    vector<int> pref(k + 1);
    for (int i = 0; i < k; ++i) {
        auto v = adj[u][i];
        if (v == p)  pref[i + 1] = pref[i];
        else pref[i + 1] = pref[i] + max(down[v], 0);
    }
    vector<int> suf(k + 1);
    for (int i = k - 1; i >= 0; --i) {
        auto v = adj[u][i];
        if (v == p) suf[i] = suf[i + 1];
        else suf[i] = suf[i + 1] + max(down[v], 0);
    }

    for (int i = 0; i < k; ++i) {
        auto v = adj[u][i];
        if (v == p) continue;
        up[v] = max(a[u] + up[u] + pref[i] + suf[i + 1], 0);
    }

    for (auto v: adj[u]) {
        if (v == p) continue;
        dfs2(v, u);
    }
}

void solve () {
    cin >> n;
    for (int u = 0; u < n; ++u) {
        cin >> a[u];
        if (a[u] == 0) a[u] = -1;
    }
    for (int e = 0; e < n - 1; ++e) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 0);
    dfs2(0, 0);
    for (int u = 0; u < n; ++u) {
        cout << down[u] + up[u] << " \n"[u == n - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
