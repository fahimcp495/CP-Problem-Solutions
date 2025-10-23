#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef long long ll;

const int MAX = 200;

ll n, a[MAX][MAX], f[MAX][MAX];

void fastin(ll &n){
	register char c = getchar_unlocked();
	int neg = 0;
	while((c<48 && c!=45) || c>57)	c = getchar_unlocked();
	if(c == 45)	neg = 1, c=getchar_unlocked();
	n = 0;
	while(c>=48 && c<=57) n=(n<<3)+(n<<1)+c-48, c=getchar_unlocked();
	if(neg)	n = -n;
	return ;
}

int main(){
	int T, tc = 0;
	scanf("%d", &T);
	while(T--){
		for (int i = 0; i < MAX; ++i){
			fill(a[i], a[i]+MAX, -1);
		}
		fastin(n);
		for (int i = 0; i < n; ++i){
			for (int j = 0; j <=i; ++j){
				fastin(a[i][j]);
			}
		}
		for (int i = n; i < 2*n-1; ++i){
			for (int j = 0; j < 2*n-1-i; ++j){
				fastin(a[i][j]);
			}
		}

		f[0][0] = a[0][0];
		for (int i = 1; i < n; ++i){
			for (int j = 0; j <=i; ++j){
				if(j == 0){
					f[i][j] = f[i-1][j];
				}
				else if(j == i){
					f[i][j] = f[i-1][j-1];
				}
				else{
					f[i][j] = max(f[i-1][j-1], f[i-1][j]);
				}
				f[i][j] += a[i][j];
			}
		}
		for (int i = n; i < 2*n-1; ++i){
			for (int j = 0; j < 2*n-1-i; ++j){
				f[i][j] = max(f[i-1][j], f[i-1][j+1]);
				f[i][j] += a[i][j];
			}
		}
		printf("Case %d: %lld\n", ++tc, f[2*n-2][0]);
	}
	return 0;
}