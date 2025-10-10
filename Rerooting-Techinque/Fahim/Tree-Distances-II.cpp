#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;

int n;
vector<int> adj[N];
int sz[N];
ll down[N], up[N];

void dfs (int u, int p) {
    sz[u] = 1;
    for (auto v: adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
        down[u] += down[v] + sz[v];
    }
}

void dfs2 (int u, int p) {
    int k = adj[u].size();
    vector<ll> pref(k + 1);
    for (int i = 0; i < k; ++i) {
        int v = adj[u][i];
        if (v == p)  pref[i + 1] = pref[i];
        else pref[i + 1] = pref[i] + down[v] + sz[v];
    }
    vector<ll> suf(k + 1);
    for (int i = k - 1; i >= 0; --i) {
        int v = adj[u][i];
        if (v == p) suf[i] = suf[i + 1];
        else suf[i] = suf[i + 1] + down[v] + sz[v];
    }

    for (int i = 0; i < k; ++i) {
        int v = adj[u][i];
        if (v == p) continue;
        up[v] = (up[u] + n - sz[u]) + (pref[i] + suf[i + 1] + sz[u] - sz[v]);
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
        cout << down[u] + up[u] << " \n"[u == n - 1];
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
