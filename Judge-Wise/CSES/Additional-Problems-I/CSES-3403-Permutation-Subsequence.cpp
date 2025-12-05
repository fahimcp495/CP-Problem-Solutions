#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve() {
    int n, m; cin >> n >> m;
    int k = min(n, m);
    vector<int> a, pos(k);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x; x--;
        if (x < k) pos[x] = a.size(), a.push_back(x);
    }
    vector<int> b;
    for (int j = 0; j < m; ++j) {
        int x; cin >> x; x--;
        if (x < k) b.push_back(x);
    }
 
    vector<int> idx(k);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&] (int i, int j) {
        return pos[b[i]] < pos[b[j]];
    });
 
 
    vector<int> sorted;
    vector<int> prv(k, -1);
    for (auto i: idx) {
        auto it = lower_bound(sorted.begin(), sorted.end(), i);
        if (it != sorted.begin()) {
            prv[i] = *prev(it);
        }
        if (it == sorted.end()) sorted.push_back(i);
        else *it = i;
    }
 
    vector<int> path;
    int i = sorted.back();
    while (i != -1) {
        path.push_back(i);
        i = prv[i];
    }
    sort(path.begin(), path.end());
 
    cout << path.size() << "\n";
    for (auto i: path) {
        cout << b[i] + 1 << " ";
    }
    cout << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    solve();
}
