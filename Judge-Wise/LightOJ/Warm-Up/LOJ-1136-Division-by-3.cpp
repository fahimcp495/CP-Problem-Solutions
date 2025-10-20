#include<bits/stdc++.h>
using namespace std;

int main(){
	int T, tc = 0;
	scanf("%d", &T);
	while(T--){
		printf("Case %d: ", ++tc);
		int a, b;	cin >> a >> b;
		a--;
		cout << 2*(b/3) + (b%3 == 2) - 2*(a/3) - (a%3 == 2) << endl;
	}
	return 0;
}