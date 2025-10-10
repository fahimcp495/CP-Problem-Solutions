#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;

int n;
vector<int> adj[N];
int down[N], up[N];

// Find down[u]
void dfs (int u, int p) {
    for (auto v: adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        down[u] = max(down[u], 1 + down[v]);
    }
}

// Find up[v] assuming that up[u] is already calculated
void dfs2 (int u, int p) {
    int sz = adj[u].size();
    vector<int> pref(sz + 1, -1);
    for (int i = 0; i < sz; ++i) {
        int v = adj[u][i];
        if (v == p)  pref[i + 1] = pref[i];
        else pref[i + 1] = max(pref[i], down[v]);
    }
    vector<int> suf(sz + 1, -1);
    for (int i = sz - 1; i >= 0; --i) {
        int v = adj[u][i];
        if (v == p) suf[i] = suf[i + 1];
        else suf[i] = max(suf[i + 1], down[v]);
    }

    for (int i = 0; i < sz; ++i) {
        int v = adj[u][i];
        if (v == p) continue;
        up[v] = max({1 + up[u], 2 + pref[i], 2 + suf[i + 1]});
        dfs2(v, u);
    }
}

void solve () {
    cin >> n;
    for (int e = 0; e < n - 1; ++e) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 0);
    dfs2(0, 0);
    for (int u = 0; u < n; ++u) {
        cout << max(down[u], up[u]) << " \n"[u == n - 1];
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
