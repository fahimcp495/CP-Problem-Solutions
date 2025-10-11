// Problem link: https://cses.fi/problemset/task/1621

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  vector<int> a(n);
  for (auto &ai: a) {
    cin >> ai;
  }
  set<int> st(a.begin(), a.end());
  cout << st.size() << "\n";
}
