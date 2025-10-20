#include<bits/stdc++.h>
using namespace std;

#define unq(x)      x.erase(unique(all(x)), x.end()

int main(){
	int T, tc = 0;
	scanf("%d", &T);
	while(T--){
		printf("Case %d: ", ++tc);
		int n;	cin >> n;
		int a[n+1];
		a[0] = 2;
		for (int i = 1; i <= n; ++i){
			cin >> a[i];
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i){
			ans += ceil((a[i] - a[i-1]) / 5.0);
		}
		cout << ans << endl;
	}
	return 0;
}