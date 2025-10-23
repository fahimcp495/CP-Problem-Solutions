#include<bits/stdc++.h>
using namespace std;
 
void move_disk(int n, int src, int aux, int des) {
  if(n==0)  return ;
  move_disk(n-1, src, des, aux);
  cout << src << " " << des << "\n";
  move_disk(n-1, aux, src, des);
}
 
int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int n;  cin >> n;
  cout << (1<<n)-1 << "\n";
  move_disk(n, 1, 2, 3);
  
  return 0;
}