#include<bits/stdc++.h>
using namespace std;
 
// #include "debug.h"
 
using ll = long long;
using ull = unsigned long long;
 
ull req(ull n) {
  ull req = 0;
  ull pw10 = 1;
  while (pw10 <= n) {
    pw10 *= 10;
 
    ull q = n / pw10;
    req += q * (pw10 / 10);
 
    ull rem = n % pw10;
    if (rem + 1 > pw10 / 10) {
      req += min(pw10 / 10, rem + 1 - pw10 / 10);
    }
  }
  return req;
}
 
int main(){
  ios::sync_with_stdio(0), cin.tie(0);
 
  ull n;  cin >> n;
 
  ull lo = 1, hi = 1e18;
  while (lo <= hi) {
    ull mid = (lo + hi) / 2;
    if (req(mid) <= n)  lo = mid + 1;
    else  hi = mid - 1;
  }
 
  cout << hi;
}
