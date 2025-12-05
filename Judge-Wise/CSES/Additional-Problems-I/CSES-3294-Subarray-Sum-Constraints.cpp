#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll inf = 1e15;
 
void solve() {
    int n, m; cin >> n >> m;
    vector<array<int, 2>> adj[n + 1];
    while (m--) {
        int u, v, w; cin >> u >> v >> w; u--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, -w});
    }
    vector<ll> dis(n + 1, inf);
    
    function<bool(int)> dfs = [&] (int u) {
        for (auto [v, w]: adj[u]) {
            if (dis[v] == inf) {
                dis[v] = dis[u] + w;
                if (!dfs(v)) return false;
            }
            else {
                if (dis[v] > dis[u] + w) {
                    return false;
                }
            }
        }
        return true;
    };
 
    for (int u = 0; u <= n; ++u) {
        if (dis[u] == inf) {
            dis[u] = 0;
            if (!dfs(u)) {
                cout << "NO\n";
                return ;
            }
        }
    }
 
    cout << "YES\n";
    for (int i = 1; i <= n; ++i) {
        cout << dis[i] - dis[i - 1] << " ";
    }
    cout << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    solve();
}
