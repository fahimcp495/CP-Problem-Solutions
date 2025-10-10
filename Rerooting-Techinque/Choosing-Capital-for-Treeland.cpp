// Problem link: https://codeforces.com/contest/219/problem/D

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;

int n;
vector<array<int, 2>> adj[N];
int down[N], up[N];

void dfs (int u, int p) {
    for (auto [v, w]: adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        down[u] += w + down[v] ;
    }
}

void dfs2 (int u, int p) {
    int k = adj[u].size();
    vector<int> pref(k + 1);
    for (int i = 0; i < k; ++i) {
        auto [v, w] = adj[u][i];
        if (v == p)  pref[i + 1] = pref[i];
        else pref[i + 1] = pref[i] + down[v] + w;
    }
    vector<ll> suf(k + 1);
    for (int i = k - 1; i >= 0; --i) {
        auto [v, w] = adj[u][i];
        if (v == p) suf[i] = suf[i + 1];
        else suf[i] = suf[i + 1] + down[v] + w;
    }

    for (int i = 0; i < k; ++i) {
        auto [v, w] = adj[u][i];
        if (v == p) continue;
        up[v] = up[u] + (!w) + (pref[i] + suf[i + 1]);
        dfs2(v, u);
    }
}

void solve () {
    cin >> n;
    for (int e = 0; e < n - 1; ++e) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back({v, 0});
        adj[v].push_back({u, 1});
    }
    dfs(0, 0);
    dfs2(0, 0);
    int mn = n;
    for (int u = 0; u < n; ++u) {
        mn = min(mn, down[u] + up[u]);
    }
    cout << mn << "\n";
    for (int u = 0; u < n; ++u) {
        if (down[u] + up[u] == mn) {
            cout << u + 1 << " ";
        }
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
