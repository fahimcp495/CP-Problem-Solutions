#include<bits/stdc++.h>
using namespace std;
 
// #include "debug.h"
 
using ll = long long;
 
vector<int> get_nsel(vector<ll> &a) {
  int n = a.size();
  vector<int> nsel(n);
  stack<ll> st;
  st.push(-1);
  for (int i = 0; i < n; ++i) {
    while (st.top() != -1 and a[st.top()] >= a[i]) {
      st.pop();
    }
    nsel[i] = st.top();
    st.push(i);
  }
  return nsel;
}
 
vector<int> get_nser(vector<ll> &a) {
  int n = a.size();
  vector<int> nser(n);
  stack<ll> st;
  st.push(n);
  for (int i = n - 1; i >= 0; --i) {
    while (st.top() != n and a[st.top()] >= a[i]) {
      st.pop();
    }
    nser[i] = st.top();
    st.push(i);
  }
  return nser;
}
 
 
 
int main(){
  ios::sync_with_stdio(0), cin.tie(0);
 
  int n;  cin >> n;
  vector<ll> a(n);
  for (auto &ai: a) {
    cin >> ai;
  }
 
  vector<int> nsel = get_nsel(a);
  vector<int> nser = get_nser(a);
 
  ll ans = 0;
 
  for (int i = 0; i < n; ++i) {
    ans = max(ans, (nser[i] - nsel[i] - 1) * a[i]);
  }
 
  cout << ans << "\n";
}
