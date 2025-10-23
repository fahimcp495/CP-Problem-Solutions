#include<bits/stdc++.h>
using namespace std;

#define DBG(a)	cerr << #a << " = " << a << endl;

typedef long long ll;

const int MAX = 20;

int n, arr[MAX][3], ans[MAX][3];

int main(){
	int T, tc = 0;
	scanf("%d", &T);
	while(T--){
		cin >> n;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < 3; ++j){
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < MAX; ++i){
			fill(ans[i], ans[i]+3, 1e9+10);
		}
		for (int i = 0; i < 3; ++i){
			ans[0][i] = arr[0][i];
		}

		for (int i = 1; i < n; ++i){
			for (int j = 0; j < 3; ++j){
				for (int k = 0; k < 3; ++k){
					if(j != k){
						ans[i][j] = min(ans[i][j], ans[i-1][k]+arr[i][j]);
					}
				}
			}
		}
		printf("Case %d: %d\n", ++tc, min(ans[n-1][0], min(ans[n-1][1], ans[n-1][2])));
	}
	return 0;
}