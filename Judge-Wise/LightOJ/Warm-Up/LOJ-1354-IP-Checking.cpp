#include<bits/stdc++.h>
using namespace std;

#define dbg(a)	cerr << #a << " = " << a << endl;

int main(){
	int T, tc = 0;
	scanf("%d", &T);
	char c = getchar();
	while(T--){
		printf("Case %d: ", ++tc);
		int da, db, dc, dd;
		scanf("%d.%d.%d.%d", &da, &db, &dc, &dd);
		string b;	cin >> b;
		int i = 0;
		int ba = 0, bb = 0, bc = 0, bd = 0;
		while (b[i] != '.'){
			ba = ba*2 + b[i]-'0';
			i++;
		}
		i++;
		while (b[i] != '.'){
			bb = bb*2 + b[i]-'0';
			i++;
		}
		i++;
		while (b[i] != '.'){
			bc = bc*2 + b[i]-'0';
			i++;
		}
		i++;
		while (b[i] != '.' and i < b.size()){
			bd = bd*2 + b[i]-'0';
			i++;
		}
		if(da == ba and db == bb and dc == bc and dd == bd)	puts("Yes");
		else	puts("No");
	}
	return 0;
}