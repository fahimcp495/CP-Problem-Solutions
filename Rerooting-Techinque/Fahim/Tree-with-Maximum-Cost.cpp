#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;

int n;
vector<int> adj[N];
int a[N];
ll sum[N], down[N], up[N];

void dfs (int u, int p) {
    sum[u] = a[u];
    for (auto v: adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        sum[u] += sum[v];
        down[u] += down[v] + sum[v];
    }
}

void dfs2 (int u, int p) {
    int k = adj[u].size();
    vector<ll> pref(k + 1);
    for (int i = 0; i < k; ++i) {
        int v = adj[u][i];
        if (v == p)  pref[i + 1] = pref[i];
        else pref[i + 1] = pref[i] + down[v] + sum[v];
    }
    vector<ll> suf(k + 1);
    for (int i = k - 1; i >= 0; --i) {
        int v = adj[u][i];
        if (v == p) suf[i] = suf[i + 1];
        else suf[i] = suf[i + 1] + down[v] + sum[v];
    }

    for (int i = 0; i < k; ++i) {
        int v = adj[u][i];
        if (v == p) continue;
        up[v] = (up[u] + sum[0] - sum[u]) + (pref[i] + suf[i + 1] + sum[u] - sum[v]);
        dfs2(v, u);
    }
}

void solve () {
    cin >> n;
    for (int u = 0; u < n; ++u) {
        cin >> a[u];
    }
    for (int e = 0; e < n - 1; ++e) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 0);
    dfs2(0, 0);
    ll ans = 0;
    for (int u = 0; u < n; ++u) {
        ans = max(ans, down[u] + up[u]);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
