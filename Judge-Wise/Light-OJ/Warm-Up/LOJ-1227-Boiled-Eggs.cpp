#include<bits/stdc++.h>
using namespace std;

#define dbg(a)	cerr << #a << " = " << a << endl;

int main(){
	int T, tc = 0;
	scanf("%d", &T);
	while(T--){
		printf("Case %d: ", ++tc);
		int n, p, q;	cin >> n >> p >> q;
		int w[n];
		for (int i = 0; i < n; ++i){
			cin >> w[i];
		}
		int ans = 0;
		for (int i = 0; i < n; ++i){
			if(w[i] <= q){
				ans++;
				q -= w[i];
			}
		}
		cout << min(ans, p) << endl;
	}
	return 0;
}