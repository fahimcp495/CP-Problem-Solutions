#include<bits/stdc++.h>
using namespace std;

int reverse(int n){
	int rev = 0;
	while(n>0){
		rev = rev*10 + (n%10);
		n /= 10;
	}
	return rev;
}
int main(){
	int T, tc = 0;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		int rev = reverse(n);
		if(rev == n)	printf("Case %d: Yes\n", ++tc);
		else		printf("Case %d: No\n", ++tc);
	}
	return 0;
}