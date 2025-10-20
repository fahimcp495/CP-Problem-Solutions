#include<bits/stdc++.h>
using namespace std;

int main(){
	int T, tc = 0;
	scanf("%d", &T);
	while(T--){
		printf("Case %d: ", ++tc);
		long long n, m;	cin >> n >> m;
		cout << m*n/2 << endl;
	}
	return 0;
}