#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const int N = 1003;
const int inf = 1e9;
 
int dis[N][N], vis[N][N];
array<int, 2> par[N][N];
string par_mv[N][N];
 
void solve() {
    int a, b, x; cin >> a >> b >> x;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dis[i][j] = inf;
        }
    }
    dis[0][0] = 0;
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
    pq.push({0, 0, 0});
 
    int ua, ub;
 
    auto relax = [&] (int va, int vb, int w, string mv) {
        if (dis[va][vb] > dis[ua][ub] + w) {
            dis[va][vb] = dis[ua][ub] + w;
            par[va][vb] = {ua, ub};
            par_mv[va][vb] = mv;
            pq.push({dis[va][vb], va, vb});
            assert(va == 0 or vb == 0 or va == a or vb == b);
        }
    };
 
    while (!pq.empty()) {
        ua = pq.top()[1];
        ub = pq.top()[2];
        if (vis[ua][ub]) continue;
        pq.pop();
        relax(a, ub, a - ua, "FILL A");
        relax(ua, b, b - ub, "FILL B");
        relax(0, ub, ua, "EMPTY A");
        relax(ua, 0, ub, "EMPTY B");
        int mv = min(ua, b - ub);
        relax(ua - mv, ub + mv, mv, "MOVE A B");
        mv = min(ub, a - ua);
        relax(ua + mv, ub - mv, mv, "MOVE B A");
    }
 
    int mn = inf;
    int best_ub;
    for (int j = 0; j <= b; ++j) {
        if (mn > dis[x][j]) {
            mn = dis[x][j];
            best_ub = j;
        }
    }
 
    if (mn == inf) {
        cout << "-1\n";
        return ;
    }
 
    vector<string> moves;
    int u = x, v = best_ub;
    while (u != 0 or v != 0) {
        moves.push_back(par_mv[u][v]);
        auto [u2, v2] = par[u][v];
        u = u2;
        v = v2;
    }
 
    reverse(moves.begin(), moves.end());
    cout << moves.size() << " " << mn << "\n";
    for (auto mv: moves) {
        cout << mv << "\n";
    }
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    solve();
}
