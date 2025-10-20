#include<bits/stdc++.h>
using namespace std;

#define dbg(n)	cerr << #n " = " << n << '\n'

int solve(int n){
	int cnt1 = 0;
	while(n%2 == 0){
		cnt1++;
		n /= 2;
	}
	int cnt2 = 0;
	while (n%2 == 1){
		cnt2++;
		n /= 2;
	}
	n++;
	n = n*2;
	n = n << cnt1;
	while (--cnt2){
		n = n*2+1;
	}
	return n;

}
int main(){
	int T, tc = 0;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		int ans = solve(n);
		printf("Case %d: %d\n", ++tc, ans);
	}
	return 0;
}