#include<bits/stdc++.h>
using namespace std;

int main(){
	int T, tc = 0;
	scanf("%d", &T);
	while(T--){
		int p[4][2];
		for (int i = 0; i < 3; ++i)
		{
			scanf("%d %d", &p[i][0], &p[i][1]);
		}
		p[3][0] = p[0][0]+p[2][0]-p[1][0];
		p[3][1] = p[0][1]+p[2][1]-p[1][1];
		int ans = 0;
		for (int i = 0; i < 4; ++i)
		{
			ans += p[i][0]*p[(i+1)%4][1];
			ans -= p[i][1]*p[(i+1)%4][0];
		}
		printf("Case %d: %d %d %d\n", ++tc, p[3][0], p[3][1], abs(ans/2));
	}
}