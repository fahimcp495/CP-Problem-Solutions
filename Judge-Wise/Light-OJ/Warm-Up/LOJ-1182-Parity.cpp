#include<bits/stdc++.h>
using namespace std;

int main(){
	int T, tc = 0;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		int ans = __builtin_popcount(n);
		if(ans%2)	printf("Case %d: odd\n", ++tc);
		else		printf("Case %d: even\n", ++tc);
	}
	return 0;
}