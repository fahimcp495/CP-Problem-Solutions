#include<bits/stdc++.h>
using namespace std;

#define dbg(a)	cerr << #a " = " << a << '\n'
int main(){
	int T, tc = 0;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		int m;
		scanf("%d", &m);
		int A[n+1];
		for (int i = 0; i < n; ++i){
			scanf("%d", &A[i]);
		}
		while (m--){
			char type = getchar();
			scanf("%c", &type);
			if(type == 'S'){
				int d;
				scanf("%d", &d);
				for (int i = 0; i < n; ++i){
					A[i] += d;
				}
			}

			else if(type == 'M'){
				int d;
				scanf("%d", &d);
				for (int i = 0; i < n; ++i){
					A[i] *= d;
				}
			}

			else if(type == 'D'){
				int d;
				scanf("%d", &d);
				for (int i = 0; i < n; ++i){
					A[i] /= d;
				}
			}

			else if(type == 'R'){
				for (int i = 0; i < n/2; ++i){
					int tmp = A[i];
					A[i] = A[n-1-i];
					A[n-1-i] = tmp;
				}
			}
			else{
				int y, z;
				scanf("%d", &y);
				scanf("%d", &z);
				int tmp = A[y];
				A[y] = A[z];
				A[z] = tmp;
			}
		}
		printf("Case %d:\n", ++tc);
		for (int i = 0; i < n-1; ++i){
			printf("%d ", A[i]);
		}
		printf("%d\n", A[n-1]);
	}
	return 0;
}