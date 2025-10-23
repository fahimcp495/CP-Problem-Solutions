#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
ll pw10[19];
 
void pre() {
  pw10[0] = 1;
  for (int i = 0; i < 18; ++i){
    pw10[i+1] = pw10[i]*10;
  }
}
 
int kthDigit(ll k, int d) { //return kth digit from only d digits number
  if(d==1)  return k-1;
  for (int i = 0; i <= 10; ++i){
    if(k == pw10[d-1]*d)  return 9;
    else if(k > pw10[d-1]*d) k -= pw10[d-1]*d;
    else {
      if(k%d==1)  return i;
      return kthDigit(k-(k+d-1)/d, d-1);
     }
   } 
   return 0;
}
 
int main(){
  ios::sync_with_stdio(0), cin.tie(0);
 
  pre();
 
  int q;  cin >> q;
  while (q--){
    ll k; cin >> k;
    ll idx = k;
    if(k<=9) {
      cout << k << "\n";
      continue;
    }
    ll d = 1;
    while (1){
      ll tot = 9*pw10[d-1]*(d);
      if(k > tot) k -= tot, d++;
      else  break;
    }
    k += pw10[d-1]*d;
    cout << kthDigit(k, d) << "\n";
  }
  
  return 0;
}