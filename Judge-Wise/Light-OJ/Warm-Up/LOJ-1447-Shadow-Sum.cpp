#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int T; cin >> T;
  for(int tc=1; tc<=T; tc++){
    cout << "Case " << tc << ": ";
    int n;  cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i){
      cin >> a[i];
    }
    vector<int> taken(20001);
    int sum = 0;
    for (int i = n-1; i >= 0; --i){
      if (!taken[abs(a[i])]) sum += a[i];
      taken[abs(a[i])] = 1;
    }
    cout << sum << '\n';
  }
  
  return 0;
}