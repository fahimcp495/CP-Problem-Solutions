#include<bits/stdc++.h>
using namespace std;

#define dbg(a)	cerr << #a << " = " << a << endl;

int main(){
	int T, tc = 0;
	scanf("%d", &T);
	while(T--){
		printf("Case %d: ", ++tc);
		string a;	cin >> a;
		long long b;	cin >> b;
		long long aValue = 0;
		int n = a.size();
		int i = 0;
		if(a[0] == '-')	i++;
		for (; i < n; ++i){
			aValue = aValue * 10 + (a[i]-'0');
			aValue %=  b;
		}
		if(aValue == 0)	puts("divisible");
		else	puts("not divisible");
	}
	return 0;
}