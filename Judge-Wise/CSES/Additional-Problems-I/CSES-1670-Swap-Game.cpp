#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
vector<array<int, 2>> mv = {{0, 1}, {1, 2}, {3, 4}, {4, 5}, {6, 7}, {7, 8},
                              {0, 3}, {1, 4}, {2, 5}, {3, 6}, {4, 7}, {5, 8}};
 
int fn (int u, int i, int j) {
  string s = to_string(u);
  swap(s[i], s[j]);
  return stoi(s);
}
 
void solve() {
  int s = 0;
  for (int i = 0; i < 9; ++i) {
    int d;  cin >> d;
    s = s * 10 + d;
  }
  int t = 123456789;
 
  if (s == t) {
    cout << "0\n";
    return ;
  }
 
  queue<int> q;  q.push(s);
  unordered_map<int, int> dis;  dis[s] = 0;
 
  while (!q.empty()) {
    int u = q.front();  q.pop();
    for (auto [i, j]: mv) {
      int v = fn(u, i, j);
      if (!dis.count(v)) {
        dis[v] = dis[u] + 1;
        if (v == t) {
          cout << dis[t] << "\n";
          return ;
        }
        q.push(v);
      }
    }
  }
}
 
int main(){
  ios::sync_with_stdio(0), cin.tie(0);
 
  int tc = 1;
  for (int t = 1; t <= tc; ++t) {
    solve();
  }
}