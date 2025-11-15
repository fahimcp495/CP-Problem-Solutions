#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;

    while(t--) {
        int n, m; cin >> n >> m;
        vector<tuple<int, int, int>> reacts;

        unordered_set<int> present;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            present.insert(x);
        }

        for(int i = 0; i < m; i++) {
            int u, v, w; cin >> u >> v >> w;
            reacts.emplace_back(u, v, w);
        }

        bool changed = true;
        while(changed) {
            changed = false;
            vector<tuple<int, int, int>> unused;
            for(auto [x, y, z] : reacts) {
                if(present.count(x) and present.count(y)) {
                    changed = true;
                    present.insert(z);
                } else {
                    unused.emplace_back(x, y, z);
                }
            }
            reacts = unused;
        }

        cout << present.size() << '\n';
    }

    return 0;
}
