#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int T, tc = 0;
	scanf("%d", &T);
	while(T--){
		printf("Case %d: ", ++tc);

		ll n, k;	cin >> n >> k;
		if(k > n)	puts("0");
		else{
			ll ans = 1;
			for (int i = 1; i <= k; ++i){
				ans *= (n-i+1);
				ans /= i;
			}
			for (int i = 1; i <= k; ++i){
				ans *= (n-i+1);
			}
			cout << ans << endl;
		}
	}
	return 0;
}