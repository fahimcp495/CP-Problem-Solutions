#include<bits/stdc++.h>
using namespace std;

#define dbg(a)	cerr << #a << " = " << a << endl;

int main(){
	int T, tc = 0;
	scanf("%d", &T);
	char c = getchar();
	while(T--){
		printf("Case %d:\n", ++tc);
		int n;	cin >> n;
		int ans = 0;
		for (int i = 0; i < n; ++i){
			string s;	cin >> s;
			if(s == "donate"){
				int k;	cin >> k;
				ans += k;
			}
			else{
				cout << ans << endl;
			}
		}
	}
	return 0;
}