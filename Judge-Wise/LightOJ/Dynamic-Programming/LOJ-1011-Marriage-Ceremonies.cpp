#include<bits/stdc++.h>
using namespace std;

int main(){
	int T, tc = 0;
	scanf("%d", &T);
	while(T--){
		printf("Case %d: ", ++tc);

		int n;	cin >> n;
		int p[n][n];
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				cin >> p[i][j];
			}
		}

		int dp[1<<n];
		for (int i = 0; i < (1<<n); ++i){
			dp[i] = -1;
		}
		dp[0] = 0;

		for (int mask = 0; mask < (1<<n); ++mask){
			int x = __builtin_popcount(mask);
			for (int j = 0; j < n; ++j){
				if(!(mask & (1<<j))){
					dp[mask | (1<<j)] = max(dp[mask | (1<<j)], dp[mask] + p[x][j]);
				}
			}
		}

		cout << dp[(1<<n)-1] << endl;

	}

	return 0;
}