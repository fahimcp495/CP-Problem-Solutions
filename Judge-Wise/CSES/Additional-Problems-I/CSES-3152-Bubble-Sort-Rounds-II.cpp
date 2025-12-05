CSES
fahimcp495 —  
Shared code
Link to this code: https://cses.fi/paste/c70f4b866017ce99eb2d03/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T> using oset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
const int N = 2e5 + 5;
 
int n, k;
int st[4 * N];
 
void add(int i, int u = 1, int s = 0, int e = n - 1) {
    if (s == e) {
        st[u] = 1;
        return ;
    }
    int v = u << 1, w = v | 1, m = (s + e) >> 1;
    if (i <= m) add(i, v, s, m);
    else add(i, w, m + 1, e);
    st[u] = st[v] + st[w];
}
 
int kth(int i, int &k, int u = 1, int s = 0, int e = n - 1) {
    if (e < i) return n;
    if (s == e) {
        if (k <= st[u]) return s;
        k -= st[u];
        return n;
    }
    if (i <= s) {
        if (st[u] < k) {
            k -= st[u];
            return n;
        }    
    }
    int v = u << 1, w = v | 1, m = (s + e) >> 1;
    int ret = kth(i, k, v, s, m);
    if (ret != n) return ret;
    return kth(i, k, w, m + 1, e);
}
 
void solve() {
    cin >> n >> k;
    vector<int> a(n);
    for (auto &ai: a) {
        cin >> ai;
    }
    vector<int> greater_left(n);
    oset<int> st;
    for (int i = 0; i < n; ++i) {
        greater_left[i] = st.order_of_key(-a[i]);
        st.insert(-a[i]);
    }
 
    priority_queue<array<int, 2>> pq;
    for (int i = 0; i < n; ++i) {
        pq.push({a[i], i});
    }
    vector<int> b(n);
    while (!pq.empty()) {
        auto [x, i] = pq.top(); pq.pop();
        int L = min(k, greater_left[i]);
        int rem = k - L;
        int R = 0;
        if (rem > 0) {
            int tmp = rem;
            R = kth(i, rem) - i - 1;
            R -= tmp - rem;
        }
        int j = i - L + R;
        b[j] = a[i];
        add(i, 1);
    }
 
    for (auto &bi: b) {
        cout << bi << " ";
    }
    cout << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    solve();
}