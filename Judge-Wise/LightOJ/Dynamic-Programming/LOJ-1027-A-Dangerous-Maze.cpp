#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int T; cin >> T;
  for(int tc=1; tc<=T; tc++){
    cout << "Case " << tc << ": ";
    int n;  cin >> n;
    int pos=0, sum=0;
    for (int i = 0; i < n; ++i){
      int xi;  cin >> xi;
      if(xi>=0) pos++, sum += xi;
      else  sum += -xi;
    }
    if(pos==0)  cout << "inf" << endl;
    else{
      int g = __gcd(sum, pos);
      cout << sum/g << "/" << pos/g << endl;
    }
  }
  
  return 0;
}