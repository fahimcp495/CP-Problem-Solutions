#include<bits/stdc++.h>
using namespace std;

int main(){
	int T, tc = 0;
	scanf("%d", &T);
	while(T--){
		printf("Case %d: ", ++tc);
		long long r1, c1, r2, c2;	cin >> r1 >> c1 >> r2 >> c2;
		if(((r1-r2)-(c1-c2))%2 != 0 and ((r1-r2)+(c1-c2))%2 != 0 ){
			puts("impossible");
		}
		else{
			if(abs(r1-r2) == abs(c1-c2))	puts("1");
			else	puts("2");
		}
	}
	return 0;
}