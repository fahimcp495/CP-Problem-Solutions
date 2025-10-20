#include<bits/stdc++.h>
using namespace std;

int main(){
	int T, tc = 0;
	scanf("%d", &T);
	while(T--){
		printf("Case %d: ", ++tc);
		double v1, v2, v3, a1, a2;	cin >> v1 >> v2 >> v3 >> a1 >> a2;
		cout << fixed << setprecision(10) << (v1*v1) / 2 / a1 + (v2*v2) / 2 / a2 << " " <<  v3 * max(v1/a1, v2/a2) << endl;
	}
	return 0;
}