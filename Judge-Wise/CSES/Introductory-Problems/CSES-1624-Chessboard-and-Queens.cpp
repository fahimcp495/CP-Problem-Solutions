#include<bits/stdc++.h>
using namespace std;
 
const int N=8;
 
vector<string> chess(N);
int ans = 0;
 
void count(int col, vector<int> row, vector<int> flag) {
  if(col==N) {
    int ok = 1;
    vector<int> cnt(15), cnt2(15);
    for (int i = 0; i < N; ++i){
      if(chess[row[i]][i]=='*') ok = 0;
      cnt[row[i]+i]++;
      cnt2[N-1+row[i]-i]++;
    }
    for (int i = 0; i < 15; ++i){
      if(cnt[i]>1 or cnt2[i]>1)  ok = 0;
    }
    ans += ok;
    return ;
  }
  for (int i = 0; i < N; ++i){
    if(!flag[i]) {
      row[col] = i;
      flag[i]=1;
      count(col+1, row, flag);
      flag[i]=0;
    }
  }
}
 
int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  for (int i = 0; i < N; ++i){
    cin >> chess[i];
  }
  vector<int> row(8), flag(8);
  count(0, row, flag);
 
  cout << ans << "\n";
  
  return 0;
}