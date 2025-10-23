#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

vector<int> divs[N];
void pc_divs(){
  for (int i = 1; i < N; ++i){
    for (int j = i; j < N; j+=i){
      divs[j].push_back(i);
    }
  }
}

double dp[N];
void pre(){
  dp[1]=0;
  for (int i = 2; i < N; ++i){
    double sum = divs[i].size();
    for(int j=0; j<divs[i].size()-1; j++){
      sum += dp[divs[i][j]];
    }
    dp[i] = sum/(divs[i].size()-1);
  }
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  pc_divs();
  pre();
  
  int T; cin >> T;
  for(int tc=1; tc<=T; tc++){
    cout << "Case " << tc << ": ";
    int n;  cin >> n;
    cout << fixed << setprecision(15);
    cout << dp[n] << endl;
  }
  
  return 0;
}



/*
dp[n] = 1/sigma(n)*(dp[d_1]+1) + 1/sigma(n)*(dp[d_2]+1) + ... + 1/sigma(n)*(dp[n]+1)
dp[n] = 1/sigma(n)*(dp[d_1]+dp[d_2]+...+dp[n] + sigma(n))
dp[n] - 1\sigma(n)*dp[n] = 1/sigma(n)*(dp[d_1]+dp[d_2]+... + sigma(n))
(sigma(n)-1)/sigma(n)*dp[n] =  1/sigma(n)*(dp[d_1]+dp[d_2]+... + sigma(n))
dp[n] = 1/(sigma(n)-1)*(dp[d_1]+dp[d_2]+... + sigma(n))
*/

